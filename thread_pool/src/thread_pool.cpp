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
        thread_status_ = true;

        task_que_.resize(thread_pool_size_);

        manager_thread_ = std::make_unique<std::thread>(&Thread_pool::manager_, this);
    }

    void Thread_pool::deinit_()
    {
        if (manager_thread_.get()->joinable())
        {
            manager_thread_.get()->join();
        }
        thread_status_ = false;
        std::cout << "end!\n";
    }

    void Thread_pool::manager_()
    {
        std::cout << "run!\n";
        while (thread_status_)
        {
            // buf_pool is empth
            if (buf_pool_.empty())
            {
                std::cout << "thread pool is empty :)" << std::endl;
                WAIT_TIME(1);
            }
            else
            {
                for (size_t i = 0; i < buf_pool_.size(); ++i)
                {
                    auto top_task = outque_();
                    task_que_[i%thread_pool_size_] = std::thread(top_task);
                    task_que_[i%thread_pool_size_].detach();
                    std::cout << "therad worker " << i%thread_pool_size_ << std::flush << std::endl; 
                }
            }
        }
    }

    //  external interface
    void Thread_pool::put_in_pool(std::function<void()> t)
    {
        enque_(t);
    }

    // thread safe queue
    void Thread_pool::enque_(task t)
    {
        std::unique_lock<std::mutex> lock(insert_mutes_);
        buf_pool_.push(t);
    }

    task Thread_pool::outque_()
    {
        std::unique_lock<std::mutex> lock(insert_mutes_);
        auto top_task = buf_pool_.front();
        buf_pool_.pop();
        return top_task;
    }
} // namespace conghuajidan
