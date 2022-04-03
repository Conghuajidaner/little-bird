#include "./thread_pool.h"

namespace conghuajidan
{
    Thread_pool::Thread_pool(size_t thread_pool_size)
    {
        thread_pool_size_ = thread_pool_size;
        init_();
    }

    Thread_pool::~Thread_pool()
    {
        deinit_();
    }

    void Thread_pool::init_()
    {
        // init thread pool
        thread_switch_ = true;

        task_que_.resize(thread_pool_size_);
        for (auto &e: task_que_) {
            e = std::thread();
        }

        manager_thread_ = std::make_unique<std::thread>(&Thread_pool::manager_, this);

        manager_thread_.get()->detach();
    }

    void Thread_pool::deinit_()
    {

        thread_switch_ = false;

        for (auto &e : task_que_) {
            if (e.joinable()) {
                e.join();
            }
        }
        if (manager_thread_.get()->joinable()) {
            manager_thread_.get()->join();
        }
        std::cout << "end!\n";
    }

    int Thread_pool::get_pool_size()
    {
        return int(task_que_.size());
    }

    void Thread_pool::manager_()
    {
        while (thread_switch_)
        {
            std::cout << "run!\n";
            // buf_pool is empth
            if (buf_pool_.empty())
            {
                // std::cout << std::to_string(task_que_.size()) + "\n";
                // WAIT_TIME;
            } else {
                // The task queue is full
                // if (/* condition */)
                // {
                //     /* code */
                // }
            }
        }
    }

    //  external interface
    void Thread_pool::put_in_pool()
    {

    }

    // thread safe queue
    void Thread_pool::enque_(Task &task)
    {
        std::unique_lock<std::mutex> lock(insert_mutes_);
        buf_pool_.push(task);
    }

    Task Thread_pool::outque_()
    {
        std::unique_lock<std::mutex> lock(insert_mutes_);
        auto top_task = buf_pool_.front();
        buf_pool_.pop();
        return top_task;
    }
} // namespace conghuajidan
