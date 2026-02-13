#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>

std::string toLowercase(const std::string& str) {
    std::string result = "";
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <N>" << std::endl;
        return 1;
    }

    std::string input_file = argv[1];
    int N = std::stoi(argv[2]);

    std::ifstream file(input_file);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << input_file << std::endl;
        return 1;
    }

    std::unordered_map<std::string, int> word_counts;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            // Remove punctuation and convert to lowercase
            std::string clean_word = "";
            for (char c : word) {
                if (std::isalnum(c)) {
                    clean_word += c;
                }
            }
            clean_word = toLowercase(clean_word);

            if (!clean_word.empty()) {
                word_counts[clean_word]++;
            }
        }
    }

    // Convert map to vector of pairs for sorting
    std::vector<std::pair<std::string, int>> word_vector(word_counts.begin(), word_counts.end());

    // Sort by frequency in descending order
    std::sort(word_vector.begin(), word_vector.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Print the top N words
    for (int i = 0; i < std::min((int)word_vector.size(), N); ++i) {
        std::cout << word_vector[i].first << ": " << word_vector[i].second << std::endl;
    }

    return 0;
}