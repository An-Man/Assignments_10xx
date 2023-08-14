/* 
Exercise 3

Repeat exercise 2, but use mutexes to lock the summation so only one
thread can do the increment at a time (check out std::lock_guard as well)
*/

#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

static int g_count {};
static std::mutex g_count_mutex;

void add(int increment, int N) {
    // g_count_mutex.lock();              // an alternative to the lock guard
    std::lock_guard count_lock{g_count_mutex};
    for (int i = 0; i < N; ++i) {
        g_count += increment;
    }
    // g_count_mutex.unlock();
}

int main() {
    
    { std::vector<std::jthread> threads; // this in a block to make it finish
                                         // before printing
        for (int i = 0; i < 100; ++i) {
            threads.push_back(std::jthread(add, 1,5));
        }
    }

    std::cout << g_count << '\n';

    // the next bit always produces 500
    // g_count = 0;

    // for (int i = 0; i < 100; ++i) {
    //     add(1,5);
    // }

    // std::cout << g_count << '\n';
}