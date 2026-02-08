#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <password>" << std::endl;
    return 1;
  }

  std::string password = argv[1];
  int score = 0;

  // Length
  if (password.length() >= 8) {
    score += 20;
  } else {
    score += password.length() * 2;
  }

  // Uppercase letters
  if (std::any_of(password.begin(), password.end(), ::isupper)) {
    score += 20;
  }

  // Lowercase letters
  if (std::any_of(password.begin(), password.end(), ::islower)) {
    score += 20;
  }

  // Digits
  if (std::any_of(password.begin(), password.end(), ::isdigit)) {
    score += 20;
  }

  // Special characters
  std::string special_chars = "!@#$%^&*()-+={}[]|\\:;'<>,.?/\"";
  if (std::any_of(password.begin(), password.end(), [&](char c) { return special_chars.find(c) != std::string::npos; })) {
    score += 20;
  }

  std::string strength;
  if (score >= 80) {
    strength = "Very Strong";
  } else if (score >= 60) {
    strength = "Strong";
  } else if (score >= 40) {
    strength = "Moderate";
  } else {
    strength = "Weak";
  }

  std::cout << "Password Strength: " << strength << std::endl;

  return 0;
}