#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int calculatePasswordStrength(const std::string& password) {
    int score = 0;

    // Length bonus
    score += password.length() * 4;

    // Uppercase letters bonus
    int uppercaseCount = 0;
    for (char c : password) {
        if (std::isupper(c)) {
            uppercaseCount++;
        }
    }
    score += uppercaseCount * 2;

    // Lowercase letters bonus
    int lowercaseCount = 0;
    for (char c : password) {
        if (std::islower(c)) {
            lowercaseCount++;
        }
    }
    score += lowercaseCount * 2;

    // Numbers bonus
    int digitCount = 0;
    for (char c : password) {
        if (std::isdigit(c)) {
            digitCount++;
        }
    }
    score += digitCount * 3;

    // Symbols bonus
    int symbolCount = 0;
    for (char c : password) {
        if (std::ispunct(c)) {
            symbolCount++;
        }
    }
    score += symbolCount * 5;

    // Variety bonus
    int varietyCount = 0;
    if (uppercaseCount > 0) varietyCount++;
    if (lowercaseCount > 0) varietyCount++;
    if (digitCount > 0) varietyCount++;
    if (symbolCount > 0) varietyCount++;
    score += varietyCount * 5;

    return score;
}

std::string assessPasswordStrength(int score) {
    if (score < 50) {
        return "Very Weak";
    } else if (score < 80) {
        return "Weak";
    } else if (score < 120) {
        return "Moderate";
    } else if (score < 160) {
        return "Strong";
    } else {
        return "Very Strong";
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <password>" << std::endl;
        return 1;
    }

    std::string password = argv[1];
    int strength = calculatePasswordStrength(password);
    std::string assessment = assessPasswordStrength(strength);

    std::cout << "Password Strength Score: " << strength << std::endl;
    std::cout << "Assessment: " << assessment << std::endl;

    return 0;
}