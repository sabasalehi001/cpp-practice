#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int calculate_password_strength(const std::string& password) {
    int score = 0;
    int length = password.length();

    // Length bonus
    score += length * 4;

    // Character type bonuses
    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_symbol = false;

    for (char c : password) {
        if (std::isupper(c)) has_upper = true;
        if (std::islower(c)) has_lower = true;
        if (std::isdigit(c)) has_digit = true;
        if (std::ispunct(c)) has_symbol = true;
    }

    if (has_upper) score += 10;
    if (has_lower) score += 10;
    if (has_digit) score += 10;
    if (has_symbol) score += 10;

    // Combination bonuses
    int combination_count = 0;
    if (has_upper) combination_count++;
    if (has_lower) combination_count++;
    if (has_digit) combination_count++;
    if (has_symbol) combination_count++;

    if (combination_count >= 3) score += combination_count * 5; // Award more if more character types are present.

    // Penalty for all lowercase or all uppercase
    if (!has_upper && !has_lower) score -= 15;
    if(std::all_of(password.begin(), password.end(), ::islower) || std::all_of(password.begin(), password.end(), ::isupper)) score -= 10;

    // Penalty for too short
    if (length < 8) score -= (8 - length) * 5;

    return std::max(0, score); // Ensure score is not negative.
}

std::string get_strength_level(int score) {
    if (score >= 80) return "Very Strong";
    else if (score >= 60) return "Strong";
    else if (score >= 40) return "Moderate";
    else return "Weak";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./app <password>" << std::endl;
        return 1;
    }

    std::string password = argv[1];
    int strength = calculate_password_strength(password);
    std::string level = get_strength_level(strength);

    std::cout << "Password Strength: " << strength << std::endl;
    std::cout << "Strength Level: " << level << std::endl;

    return 0;
}