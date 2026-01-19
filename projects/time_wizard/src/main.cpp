#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>

std::string format_current_time(const std::string& format_string) {
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm* timeinfo = std::localtime(&time);

    if (timeinfo == nullptr) {
        throw std::runtime_error("Failed to get local time information.");
    }

    char buffer[80]; // Buffer to hold the formatted time
    std::strftime(buffer, sizeof(buffer), format_string.c_str(), timeinfo);
    return buffer;
}

int main(int argc, char* argv[]) {
    std::string format = "%Y-%m-%d %H:%M:%S"; // Default format

    if (argc > 1) {
        format = argv[1]; // Use the provided format string
    }

    try {
        std::cout << format_current_time(format) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unexpected error occurred." << std::endl;
        return 1;
    }

    return 0;
}