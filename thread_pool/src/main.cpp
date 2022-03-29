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
    thread_pool.reset();
    for (size_t idx = 0; idx < CASE_NUMBER; ++ idx)
    {
        // thread_pool.put_in_pool();
    }
    return 0;
}
