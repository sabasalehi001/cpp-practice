#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <substring> <filename>" << std::endl;
        return 1;
    }

    std::string substring = argv[1];
    std::string filename = argv[2];

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
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