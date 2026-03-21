#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <password>" << std::endl;
        return 1;
    }

    std::string password = argv[1];
    int score = 0;
    std::string feedback = "";

    // Length check
    if (password.length() >= 8) {
        score += 20;
    } else {
        feedback += "Password should be at least 8 characters long. ";
    }

    // Uppercase letters
    bool hasUppercase = std::any_of(password.begin(), password.end(), [](unsigned char c){ return std::isupper(c); });
    if (hasUppercase) {
        score += 15;
    } else {
        feedback += "Password should contain at least one uppercase letter. ";
    }

    // Lowercase letters
    bool hasLowercase = std::any_of(password.begin(), password.end(), [](unsigned char c){ return std::islower(c); });
    if (hasLowercase) {
        score += 15;
    } else {
        feedback += "Password should contain at least one lowercase letter. ";
    }

    // Digits
    bool hasDigit = std::any_of(password.begin(), password.end(), [](unsigned char c){ return std::isdigit(c); });
    if (hasDigit) {
        score += 20;
    } else {
        feedback += "Password should contain at least one digit. ";
    }

    // Special characters
    bool hasSpecialChar = std::any_of(password.begin(), password.end(), [](unsigned char c){ return !std::isalnum(c); });
    if (hasSpecialChar) {
        score += 30;
    } else {
        feedback += "Password should contain at least one special character. ";
    }

    std::cout << "Password Strength: " << score << "/100" << std::endl;
    if (!feedback.empty()) {
        std::cout << "Feedback: " << feedback << std::endl;
    } else {
        std::cout << "Password is strong!" << std::endl;
    }

    return 0;
}