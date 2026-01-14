#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>

std::string format_time(const std::string& format, time_t timestamp) {
    std::tm timeinfo;
#ifdef _MSC_VER
    localtime_s(&timeinfo, &timestamp);
#else
    localtime_r(&timestamp, &timeinfo);
#endif

    std::stringstream ss;
    ss << std::put_time(&timeinfo, format.c_str());
    if (ss.fail()) {
        throw std::runtime_error("Formatting failed. Check format string.");
    }
    return ss.str();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <format_string> <timestamp>" << std::endl;
        return 1;
    }

    try {
        std::string format = argv[1];
        time_t timestamp = std::stoll(argv[2]);

        std::string formatted_time = format_time(format, timestamp);
        std::cout << formatted_time << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid timestamp: " << e.what() << std::endl;
        return 1;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}