#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string compress(const std::string& input) {
    std::stringstream compressed;
    if (input.empty()) return "";

    char current_char = input[0];
    int count = 1;

    for (size_t i = 1; i < input.length(); ++i) {
        if (input[i] == current_char) {
            count++;
        } else {
            compressed << count << current_char;
            current_char = input[i];
            count = 1;
        }
    }
    compressed << count << current_char;

    return compressed.str();
}

std::string decompress(const std::string& input) {
    std::stringstream decompressed;
    std::string count_str;

    for (size_t i = 0; i < input.length(); ++i) {
        if (isdigit(input[i])) {
            count_str += input[i];
        } else {
            if (!count_str.empty()) {
                int count = std::stoi(count_str);
                decompressed << std::string(count, input[i]);
                count_str = "";
            }
        }
    }
    return decompressed.str();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./app -c <string_to_compress> OR ./app -d <string_to_decompress>" << std::endl;
        return 1;
    }

    std::string option = argv[1];
    std::string data = argv[2];

    if (option == "-c") {
        std::cout << compress(data) << std::endl;
    } else if (option == "-d") {
        std::cout << decompress(data) << std::endl;
    } else {
        std::cerr << "Invalid option. Use -c for compress or -d for decompress." << std::endl;
        return 1;
    }

    return 0;
}