#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int calculate_strength(const std::string& password) {
    int score = 0;
    int length = password.length();

    // Length bonus
    score += length * 4;

    // Uppercase letters bonus
    int uppercase_count = 0;
    for (char c : password) {
        if (std::isupper(c)) {
            uppercase_count++;
        }
    }
    score += uppercase_count * 2;

    // Lowercase letters bonus
    int lowercase_count = 0;
    for (char c : password) {
        if (std::islower(c)) {
            lowercase_count++;
        }
    }
    score += lowercase_count * 2;

    // Numbers bonus
    int digit_count = 0;
    for (char c : password) {
        if (std::isdigit(c)) {
            digit_count++;
        }
    }
    score += digit_count * 3;

    // Symbols bonus
    int symbol_count = 0;
    for (char c : password) {
        if (std::ispunct(c)) {
            symbol_count++;
        }
    }
    score += symbol_count * 5;

    // Middle numbers or symbols bonus
    int middle_char_count = 0;
    for (size_t i = 1; i < password.length() - 1; ++i) {
        if (std::isdigit(password[i]) || std::ispunct(password[i])) {
            middle_char_count++;
        }
    }
    score += middle_char_count * 2;

    // Requirements bonus (min 3 of: uppercase, lowercase, number, symbol)
    int requirements_met = 0;
    if (uppercase_count > 0) requirements_met++;
    if (lowercase_count > 0) requirements_met++;
    if (digit_count > 0) requirements_met++;
    if (symbol_count > 0) requirements_met++;
    if (requirements_met >= 3) {
        score += requirements_met * 5;
    }

    // Deduction for only letters
    if ((uppercase_count + lowercase_count == length) && (digit_count == 0) && (symbol_count == 0)) {
        score -= length;
    }

    // Deduction for only numbers
    if ((digit_count == length) && (uppercase_count == 0) && (lowercase_count == 0) && (symbol_count == 0)) {
        score -= length;
    }

    return std::max(0, std::min(score, 100)); // Clamp score between 0 and 100
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <password>" << std::endl;
        return 1;
    }

    std::string password = argv[1];
    int strength = calculate_strength(password);

    std::cout << "Password Strength: " << strength << "%" << std::endl;

    if (strength < 30) {
        std::cout << "Weak password.  Consider using a longer password with a mix of characters." << std::endl;
    } else if (strength < 60) {
        std::cout << "Moderate password.  Adding more complexity would improve security." << std::endl;
    } else if (strength < 80) {
        std::cout << "Strong password." << std::endl;
    } else {
        std::cout << "Very strong password." << std::endl;
    }

    return 0;
}
