/* 
Exercise 2

Create a function that adds an integer n times to a static global
variable.  e.g. void add(int increment int times);  Use a loop to do the 
increments.

Create 100 threads from the main() function to call the add-function.

Compare the result to straight-up calculation.
*/

#include <thread>
#include <iostream>
#include <vector>

static int g_count {};

void add(int increment, int N) {
    for (int i = 0; i < N; ++i) {
        g_count += increment;
    }
}

int main() {
    std::vector<std::jthread> threads;

    for (int i = 0; i < 100; ++i) {
        threads.push_back(std::jthread(add,1,5));
    
    }

    std::cout << g_count << '\n'; // gave anything from 265 to 495 but not 500

    // the next bit always produces 500
    // g_count = 0;

    // for (int i = 0; i < 100; ++i) {
    //     add(1,5);
    // }

    // std::cout << g_count << '\n';
}