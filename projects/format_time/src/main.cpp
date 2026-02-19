#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>
#include <stdexcept>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <timestamp> <format_string>" << std::endl;
        return 1;
    }

    try {
        // Convert the timestamp argument to a time_t
        std::time_t timestamp = std::stoll(argv[1]);

        // Create a time_point from the timestamp
        std::chrono::system_clock::time_point time_point = std::chrono::system_clock::from_time_t(timestamp);

        // Convert the time_point to a tm struct
        std::time_t tt = std::chrono::system_clock::to_time_t(time_point);
        std::tm* time_info = std::localtime(&tt);
        if (time_info == nullptr) {
            throw std::runtime_error("Failed to convert timestamp to local time.");
        }

        // Use std::put_time to format the time
        std::stringstream ss;
        ss << std::put_time(time_info, argv[2]);

        // Print the formatted time
        std::cout << ss.str() << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid timestamp.  Must be an integer." << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Timestamp out of range." << std::endl;
        return 1;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Error: An unexpected error occurred." << std::endl;
        return 1;
    }

    return 0;
}