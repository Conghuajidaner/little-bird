#ifndef _THREAD_POOL_
#define _THREAD_POOL_

#include <chrono>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>

#include <iostream>

namespace conghuajidan
{
    
    #define WAIT_TIME std::this_thread::sleep_for(std::chrono:: milliseconds (500))

    struct Task
    {
        /* data */
        std::function<void()> fun;
    };

    class Thread_pool
    {
    private:
        /* data */
        size_t thread_pool_size_;
        std::queue<Task> buf_pool_;

        // There's a better way to do it：Vector implement circular queues
        std::vector<std::thread> task_que_;

        std::mutex insert_mutes_;

        bool thread_switch_;
        std::unique_ptr<std::thread> manager_thread_;
    public:
        Thread_pool(size_t thread_pool_size);
        ~Thread_pool();
        
        // interface
        void put_in_pool();
        int get_pool_size();

    private:
        void manager_();
        void ring_buf_();

        void deinit_();
        void init_();

        // we can use the return value to represent the result
        void enque_(Task &task);
        Task outque_();
    };
} // namespace conghuajidan

#endif //_THREAD_POOL_
