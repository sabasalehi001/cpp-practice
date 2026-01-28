#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <substring> <file_path>" << std::endl;
        return 1;
    }

    std::string substring = argv[1];
    std::string file_path = argv[2];

    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return 1;
    }

    std::string line;
    int line_number = 0;
    while (std::getline(file, line)) {
        line_number++;
        if (line.find(substring) != std::string::npos) {
            std::cout << line_number << ": " << line << std::endl;
        }
    }

    file.close();
    return 0;
}