/* Exercise 1

From the main thread, create two threads, one of which prints
"Hello, " and the other "world!\n".

Run your program a couple of times. */

#include <thread>
#include <iostream>

void print_hello() {
    std::cout << "Hello\n";
}

void print_world() {
    std::cout << "World\n";
}

int main() {
    std::jthread one (print_hello); // either of these can print first
    std::jthread two (print_world);
}