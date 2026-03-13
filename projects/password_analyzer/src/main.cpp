#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string password;
    std::cout << "Password: ";
    std::cin >> password;

    int score = 0;

    // Length bonus
    score += password.length();

    // Character type bonuses
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (char c : password) {
        if (isupper(c)) hasUpper = true;
        if (islower(c)) hasLower = true;
        if (isdigit(c)) hasDigit = true;
        if (ispunct(c)) hasSpecial = true;
    }

    if (hasUpper) score += 10;
    if (hasLower) score += 10;
    if (hasDigit) score += 10;
    if (hasSpecial) score += 10;

    std::string strength;
    if (score < 30) {
        strength = "Weak";
    } else if (score < 50) {
        strength = "Moderate";
    } else {
        strength = "Strong";
    }

    std::cout << "Password Strength: " << strength << std::endl;

    return 0;
}