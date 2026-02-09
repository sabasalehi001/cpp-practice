#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

std::string format_time(const std::string& format_string = "%Y-%m-%d %H:%M:%S") {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_c); // Use localtime for local time

    std::stringstream ss;
    ss << std::put_time(&now_tm, format_string.c_str());
    return ss.str();
}

int main(int argc, char* argv[]) {
    std::string format_string;
    if (argc > 1) {
        format_string = argv[1];
    } else {
        format_string = "%Y-%m-%d %H:%M:%S";
    }

    std::cout << format_time(format_string) << std::endl;

    return 0;
}