#include <iostream>
#include <string>
#include <thread>
#include "thread_pool.h"

using namespace conghuajidan;

constexpr size_t CASE_NUMBER = 100;

void test()
{
    static int num = 1;
    std::cout << std::to_string(num++) + "test function!\n";
}

int main()
{
    auto thread_pool = std::make_unique<Thread_pool>(size_t(1000));
    std::cout << std::thread::hardware_concurrency() - 2 << std::endl;
    while (true)
    {
        // WAIT_TIME(1);
        thread_pool->put_in_pool(test);
        thread_pool->put_in_pool(test);
        thread_pool->put_in_pool(test);
        thread_pool->put_in_pool(test);
    }
    return 0;
}
