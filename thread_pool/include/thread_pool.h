#ifndef _THREAD_POOL_
#define _THREAD_POOL_

#include <atomic>
#include <chrono>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>

#include <iostream>

namespace conghuajidan
{

#define WAIT_TIME(s) std::this_thread::sleep_for(std::chrono::seconds(s))

    using task = std::function<void()>;

    using p_size = uint8_t;

    class Thread_pool
    {
    private:
        /* data */
        p_size thread_pool_size_;
        std::queue<std::function<void()>> buf_pool_;

        // There's a better way to do it：Vector implement circular queues
        std::vector<std::thread> task_que_;

        std::mutex insert_mutes_;

        std::atomic<bool> thread_status_;
        std::unique_ptr<std::thread> manager_thread_;

    public:
        Thread_pool() = delete;
        Thread_pool(size_t thread_pool_size);
        ~Thread_pool();

        // interface
        void put_in_pool(task);

    private:
        void manager_();
        void ring_buf_();

        void deinit_();
        void init_();

        // we can use the return value to represent the result
        void enque_(task t);
        task outque_();
    };
} // namespace conghuajidan

#endif //_THREAD_POOL_
