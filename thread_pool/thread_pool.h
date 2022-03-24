#ifndef _THREAD_POOL_
#define _THREAD_POOL_

#include <mutex>
#include <queue>
#include <thread>

namespace conghuajidan
{
    struct Task
    {
        uint8_t level;

        /* data */
        bool operator<(const Task& t)
        {
            return level < t.level;
        }
    };

    class Thread_pool
    {
    private:
        /* data */
        size_t thread_pool_size;
        std::priority_queue<Task> buf_pool_;

        // There's a better way to do it：Vector implement circular queues
        std::queue<Task> task_que_;


        std::mutex insert_mutes_;
    public:
        Thread_pool(/* args */);
        ~Thread_pool();

        // interface

    private:
        void manager_();
        void deinit_();
        void init_();

        // we can use the return value to represent the result
        void enque_(Task& t);
    };
} // namespace conghuajidan

#endif //_THREAD_POOL_
