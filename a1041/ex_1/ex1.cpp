/* Exercise 1

Trying out the "libfmt" library */

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <string>
#include <vector>

int main() {
    std::string world = "world";
    std::string world2 = "another world";

    std::vector<std::string> worlds;

    worlds.push_back(world);
    worlds.push_back(world2);
    
    fmt::print("hello {}\n", world);
    fmt::print("hello {}\n", world2);
    
    fmt::print("{}\n", worlds); // print container
}