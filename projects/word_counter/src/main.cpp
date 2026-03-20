#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>

// Function to convert a string to lowercase
std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to remove punctuation from a string
std::string removePunctuation(const std::string& str) {
    std::string result = "";
    for (char c : str) {
        if (std::isalnum(c) || std::isspace(c)) {
            result += c;
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <top_n>" << std::endl;
        return 1;
    }

    std::string input_file = argv[1];
    int top_n = std::stoi(argv[2]);

    std::ifstream file(input_file);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << input_file << std::endl;
        return 1;
    }

    std::map<std::string, int> word_counts;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            word = removePunctuation(word);
            word = toLower(word);
            if (!word.empty()) {
                word_counts[word]++;
            }
        }
    }

    file.close();

    // Sort the word counts by frequency in descending order
    std::vector<std::pair<std::string, int>> sorted_word_counts(word_counts.begin(), word_counts.end());
    std::sort(sorted_word_counts.begin(), sorted_word_counts.end(),
              [](const auto& a, const auto& b) {
                  return a.second > b.second;
              });

    // Print the top N most frequent words
    int count = 0;
    for (const auto& pair : sorted_word_counts) {
        std::cout << pair.first << ": " << pair.second << std::endl;
        count++;
        if (count >= top_n) {
            break;
        }
    }

    return 0;
}