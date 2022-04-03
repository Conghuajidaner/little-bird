#include <iostream>
#include <thread>
#include "../include/thread_pool.h"

using namespace conghuajidan;

constexpr size_t CASE_NUMBER = 100;

void test(size_t number)
{
    std::cout << std::to_string(number) + ". Hello World!\n";
}

int main()
{
    auto thread_pool = std::make_unique<Thread_pool>(100);
    for (size_t idx = 0; idx < CASE_NUMBER/100; ++ idx)
    {
        // thread_pool.put_in_pool();
        WAIT_TIME;
        std::cout << "WAIT_TIME:" + std::to_string(idx) +  "\n";
    }
    thread_pool.reset();
    return 0;
}
