#pragma once

#include <atomic>
#include <cassert>
#include <mutex>
#include <queue>
#include <thread>

namespace qwr
{

class ThreadPool
{
private:
    using Task = std::function<void()>;

public:
    ThreadPool( const std::string& threadName = "QWR Worker",
                size_t maxThreadCount = std::max<size_t>( std::thread::hardware_concurrency(), 1 ) );
    ~ThreadPool();
    ThreadPool( const ThreadPool& ) = delete;
    ThreadPool& operator=( const ThreadPool& ) = delete;

    template <typename T>
    void AddTask( T&& task )
    {
        static_assert( std::is_invocable_v<T> );
        static_assert( std::is_move_constructible_v<T> || std::is_copy_constructible_v<T> );
        // This method can be easily modified to be thread-safe, but we don't need that currently
        assert( core_api::is_main_thread() );

        if ( isExiting_ )
        {
            return;
        }

        {
            std::scoped_lock sl( queueMutex_ );

            if constexpr ( !std::is_copy_constructible_v<T> && std::is_move_constructible_v<T> )
            {
                auto taskLambda = [taskWrapper = std::make_shared<T>( std::forward<T>( task ) )] {
                    std::invoke( *taskWrapper );
                };
                tasks_.emplace( std::make_unique<Task>( taskLambda ) );
            }
            else
            {
                tasks_.emplace( std::make_unique<Task>( task ) );
            }

            hasTask_.notify_one();
        }

        {
            std::mutex queueMutex_;
            if ( !tasks_.empty() && threads_.size() < maxThreadCount_ && !idleThreadCount_ )
            {
                AddThread();
            }
        }
    }

    void Finalize();

private:
    void AddThread();
    void ThreadProc();

private:
    const std::string threadName_;
    const size_t maxThreadCount_;

    std::vector<std::unique_ptr<std::thread>> threads_;
    std::atomic_uint32_t idleThreadCount_ = 0;
    std::atomic_bool isExiting_ = false;

    std::mutex queueMutex_;
    std::condition_variable hasTask_;
    std::queue<std::unique_ptr<Task>> tasks_;
};

} // namespace qwr
