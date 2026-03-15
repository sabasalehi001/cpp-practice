#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <log_file>" << std::endl;
        return 1;
    }

    std::string log_file = argv[1];
    std::ifstream file(log_file);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << log_file << std::endl;
        return 1;
    }

    int info_count = 0;
    int warn_count = 0;
    int error_count = 0;
    std::string line;

    while (std::getline(file, line)) {
        std::string lower_line = line;
        std::transform(lower_line.begin(), lower_line.end(), lower_line.begin(), ::tolower);

        if (lower_line.find("info:") != std::string::npos) {
            info_count++;
        } else if (lower_line.find("warn:") != std::string::npos) {
            warn_count++;
        } else if (lower_line.find("error:") != std::string::npos) {
            error_count++;
        }
    }

    file.close();

    std::cout << "INFO: " << info_count << std::endl;
    std::cout << "WARN: " << warn_count << std::endl;
    std::cout << "ERROR: " << error_count << std::endl;

    return 0;
}