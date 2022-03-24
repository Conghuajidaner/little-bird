#include "./thread_pool.h"

namespace conghuajidan
{
    Thread_pool::Thread_pool()
    {
        init_();
    }

    Thread_pool::~Thread_pool()
    {
        deinit_();
    }

    void Thread_pool::init_()
    {
        // init thread pool
    }

    void Thread_pool::deinit_()
    {
        // northing to do
    }

    void Thread_pool::manager_()
    {
        
    }

    void Thread_pool::enque_(Task& t)
    {
        std::unique_lock<std::mutex> lock(insert_mutes_);
        buf_pool_.push(t);
    }
} // namespace conghuajidan
