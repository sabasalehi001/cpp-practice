#include <iostream>
#include <string>
#include <vector>

std::string compress(const std::string& input) {
    std::string compressed;
    if (input.empty()) {
        return compressed;
    }

    char currentChar = input[0];
    int count = 1;

    for (size_t i = 1; i < input.length(); ++i) {
        if (input[i] == currentChar) {
            count++;
        } else {
            compressed += std::to_string(count) + currentChar;
            currentChar = input[i];
            count = 1;
        }
    }
    compressed += std::to_string(count) + currentChar;
    return compressed;
}

std::string decompress(const std::string& input) {
    std::string decompressed;
    std::string countStr;

    for (char c : input) {
        if (isdigit(c)) {
            countStr += c;
        } else {
            if (!countStr.empty()) {
                int count = std::stoi(countStr);
                for (int i = 0; i < count; ++i) {
                    decompressed += c;
                }
                countStr = "";
            } else {
                // Handle cases where there's a character without a preceding count.
                // This could be an error, or could be a specific case in RLE.
                // For simplicity, treat as count of 1.
                decompressed += c;
            }
        }
    }
    return decompressed;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <compress|decompress> <input_string>" << std::endl;
        return 1;
    }

    std::string command = argv[1];
    std::string input = argv[2];

    if (command == "compress") {
        std::string compressed = compress(input);
        std::cout << "Compressed: " << compressed << std::endl;
    } else if (command == "decompress") {
        std::string decompressed = decompress(input);
        std::cout << "Decompressed: " << decompressed << std::endl;
    } else {
        std::cerr << "Invalid command.  Use 'compress' or 'decompress'." << std::endl;
        return 1;
    }

    return 0;
}
