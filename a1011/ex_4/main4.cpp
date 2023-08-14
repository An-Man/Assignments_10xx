/* 
Exercise 4

Repeat exercise 2, but use std::atomic type as your global sum type.
*/

#include <thread>
#include <iostream>
#include <vector>
#include <atomic>

static std::atomic<int> g_count {};

void add(int increment, int N) {
    for (int i = 0; i < N; ++i) {
        g_count += increment;
    }
}

int main() {
    
    { std::vector<std::jthread> threads; // this in a block to make it finish
                                         // before printing
        for (int i = 0; i < 100; ++i) {
            threads.push_back(std::jthread(add, 1,5));
        }
    }

    std::cout << g_count << '\n';   // seems to work ok
}