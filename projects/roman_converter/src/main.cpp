#include <iostream>
#include <string>
#include <stdexcept>

std::string to_roman(int num) {
    if (num <= 0 || num > 3999) {
        throw std::invalid_argument("Number must be between 1 and 3999");
    }

    std::string roman = "";
    int numerals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 13; ++i) {
        while (num >= numerals[i]) {
            roman += symbols[i];
            num -= numerals[i];
        }
    }

    return roman;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <integer>" << std::endl;
        return 1;
    }

    try {
        int num = std::stoi(argv[1]);
        std::string roman = to_roman(num);
        std::cout << roman << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid input: " << e.what() << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Number is too large." << std::endl;
        return 1;
    }

    return 0;
}