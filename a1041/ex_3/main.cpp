/* 
    Exercise 3

    Try nlohmann's json library.  Use it to read a json file from your hard drive and print 
    the stored contents.  (You can use e.g. json files from 
    https://github.com/LearnWebCode/json-example Then create a json file from your code
    and save that to your hard drive.
*/

#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

int main() {

    std::ifstream file("example.json");
    json data = json::parse(file); // also prints to console

    std::ofstream output("output.json");
    json out = {
        {"warm", true},
        {"temperature", 25.0},
    };
    output << out;

}