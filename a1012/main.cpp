/* 
Exercise 1:

    Create a log, a vector of strings is a decent choice for the storage.
    Knowing it will be accessed from multiple threads, think a bit how you want 
    to handle it.

    Create a function to read user input until user writes "quit" (or some 
    other way for the user to gracefully exit) Add the read input to the log.

    Create a function to add a message to the log every second.  (e.g. "one 
    second passed" or "program has been running for n seconds")

    Make the program print the log if user input matches some command e.g. "log"

    Launch both functions in separate threads, try it out.

Exercise 2:

    Implement functionality so the second loop exits gracefully if the user 
    decided to exit.
*/

#include <thread>
#include <vector>
#include <string>
#include <iostream>
#include <mutex>
#include <chrono>

using Logs = std::vector<std::string>;
static std::mutex lock_logs {};
static bool keep_logging {true};

void write_to_log(Logs& logs, std::string input) {
    std::lock_guard<std::mutex> lock {lock_logs};
    logs.push_back(input);
}

void listen_and_write_input(Logs& log) {
    std::string input {};
    std::cout << "Write text to log or 'exit' to exit:\n";
    while (std::getline(std::cin, input))
    {
        if (input == "exit") {
            keep_logging = false;
            break;
        }

        if (input == "log") {
            for (auto& elem : log) {
                std::cout << elem << '\n';
            }
        }
        write_to_log(log, input);
        std::cout << "Write text to log, 'exit' to exit or 'log' to "
        "print log :\n";
    }
}

void add_message_to_log(Logs& log) {
    std::string msg {"One second passed"};
    
    while (keep_logging) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        write_to_log(log, msg);
    }
}

int main() {

    Logs logs;

    std::jthread one (add_message_to_log, std::ref(logs));
    std::jthread two (listen_and_write_input, std::ref(logs));
}