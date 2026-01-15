#include <iostream>
#include <string>
#include <sstream>

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
    if (input.empty()) return "";

    for (size_t i = 0; i < input.length();) {
        size_t j = i;
        while (j < input.length() && std::isdigit(input[j])) {
            ++j;
        }

        if (j == i) {
            return ""; // Invalid format
        }

        int count = std::stoi(input.substr(i, j - i));
        if (j == input.length()) return "";
        char character = input[j];

        for (int k = 0; k < count; ++k) {
            decompressed << character;
        }

        i = j + 1;
    }

    return decompressed.str();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_string>" << std::endl;
        return 1;
    }

    std::string input = argv[1];

    std::cout << "Original string: " << input << std::endl;

    std::string compressed = compress(input);
    std::cout << "Compressed string: " << compressed << std::endl;

    std::string decompressed = decompress(compressed);
    std::cout << "Decompressed string: " << decompressed << std::endl;

    return 0;
}