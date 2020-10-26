#include <stdafx.h>

#include "thread_pool.h"

#include <qwr/final_action.h>
#include <qwr/thread_helpers.h>

namespace qwr
{

ThreadPool::ThreadPool( const std::string& threadName,
                        size_t maxThreadCount )
    : threadName_( threadName )
    , maxThreadCount_( std::max<size_t>( std::min( std::thread::hardware_concurrency(), maxThreadCount ), 1 ) )
{
    threads_.reserve( maxThreadCount_ );
}

ThreadPool::~ThreadPool()
{
    assert( threads_.empty() );
    assert( tasks_.empty() );
}

void ThreadPool::Finalize()
{
    assert( core_api::is_main_thread() );

    {
        std::unique_lock sl( queueMutex_ );
        isExiting_ = true;
    }

    hasTask_.notify_all();

    for ( const auto& thread: threads_ )
    {
        assert( thread );
        if ( thread->joinable() )
        {
            thread->join();
        }
    }

    threads_.clear();
    while ( !tasks_.empty() )
    { // Might be non-empty if thread was aborted
        tasks_.pop();
    }
}

void ThreadPool::AddThread()
{
    auto& ret = threads_.emplace_back( std::make_unique<std::thread>( [&] { ThreadProc(); } ) );
    qwr::SetThreadName( *ret, threadName_ );
}

void ThreadPool::ThreadProc()
{
    ++idleThreadCount_;
    const auto idleCounter = qwr::final_action( [&idleThreadsCount = idleThreadCount_]() {
        --idleThreadsCount;
    } );

    while ( true )
    {
        if ( isExiting_ )
        {
            return;
        }

        std::unique_ptr<Task> task;
        {
            std::unique_lock sl( queueMutex_ );
            hasTask_.wait(
                sl,
                [&tasks = tasks_, &isExiting = isExiting_] {
                    return ( !tasks.empty() || isExiting );
                } );

            if ( isExiting_ )
            {
                return;
            }

            task.swap( tasks_.front() );
            tasks_.pop();
        }

        --idleThreadCount_;
        try
        {
            std::invoke( *task );
        }
        catch ( const std::exception& e )
        {
            FB2K_console_formatter() << "QWR Thread Pool (error):\n"
                                     << e.what();
        }
        ++idleThreadCount_;
    }
}

} // namespace qwr
