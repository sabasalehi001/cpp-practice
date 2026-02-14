#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <password>" << std::endl;
        return 1;
    }

    std::string password = argv[1];
    int score = 0;

    // Length check
    if (password.length() >= 8) {
        score++;
    }
    if (password.length() >= 12) {
        score++;
    }

    // Character type checks
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (char c : password) {
        if (std::isupper(c)) {
            hasUpper = true;
        } else if (std::islower(c)) {
            hasLower = true;
        } else if (std::isdigit(c)) {
            hasDigit = true;
        } else {
            hasSpecial = true;
        }
    }

    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    std::cout << "Password Strength: ";
    switch (score) {
        case 0:
        case 1:
            std::cout << "Very Weak" << std::endl;
            break;
        case 2:
        case 3:
            std::cout << "Weak" << std::endl;
            break;
        case 4:
            std::cout << "Moderate" << std::endl;
            break;
        case 5:
            std::cout << "Strong" << std::endl;
            break;
        case 6:
        case 7:
            std::cout << "Very Strong" << std::endl;
            break;
        default:
            std::cout << "Error analyzing password" << std::endl;
            break;
    }

    return 0;
}