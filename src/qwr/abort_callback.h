#pragma once

#include <atomic>
#include <mutex>
#include <unordered_map>

namespace qwr
{

class GlobalAbortCallback : public abort_callback
{
public:
    static GlobalAbortCallback& GetInstance();

    void AddListener( pfc::event& listener );
    void RemoveListener( pfc::event& listener );
    void Abort();

    // abort_callback
    [[nodiscard]] bool is_aborting() const override;
    [[nodiscard]] abort_callback_event get_abort_event() const override;

private:
    abort_callback_impl abortImpl_;

    std::mutex listenerMutex_;
    std::unordered_map<void*, std::reference_wrapper<pfc::event>> listeners_;
};

class TimedAbortCallback : public abort_callback
{
public:
    TimedAbortCallback( const qwr::u8string& timeoutLogMessage = {}, uint32_t timeoutSeconds = 5 );
    TimedAbortCallback( const TimedAbortCallback& ) = delete;
    ~TimedAbortCallback();
    TimedAbortCallback& operator=( const TimedAbortCallback& ) = delete;

    // abort_callback
    bool is_aborting() const override;
    abort_callback_event get_abort_event() const override;

    static void CALLBACK timerProc( PVOID lpParameter, BOOLEAN /*TimerOrWaitFired*/ );

private:
    const qwr::u8string timeoutLogMessage_;

    pfc::event abortEvent_;
    HANDLE hTimer_ = nullptr;

    std::atomic_bool hasEnded_ = false;
};

} // namespace qwr
