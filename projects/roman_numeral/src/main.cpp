#include <iostream>
#include <string>
#include <stdexcept>

std::string to_roman(int num) {
    if (num < 1 || num > 3999) {
        throw std::out_of_range("Number must be between 1 and 3999");
    }

    std::string roman_value = "";
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 13; ++i) {
        while (num >= values[i]) {
            roman_value += symbols[i];
            num -= values[i];
        }
    }

    return roman_value;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <integer>" << std::endl;
        return 1;
    }

    try {
        int number = std::stoi(argv[1]);
        std::string roman = to_roman(number);
        std::cout << roman << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: Please provide a valid integer." << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "Number out of range: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}