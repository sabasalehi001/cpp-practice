#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <N>" << std::endl;
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
            // Remove punctuation and convert to lowercase
            word.erase(std::remove_if(word.begin(), word.end(), [](unsigned char c){ return std::ispunct(c); }), word.end());
            word = toLower(word);

            if (!word.empty()) {
                word_counts[word]++;
            }
        }
    }

    file.close();

    // Sort the word counts by frequency in descending order
    std::vector<std::pair<std::string, int>> sorted_counts(word_counts.begin(), word_counts.end());
    std::sort(sorted_counts.begin(), sorted_counts.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Print the top N words
    int count = 0;
    for (const auto& pair : sorted_counts) {
        std::cout << pair.first << ": " << pair.second << std::endl;
        count++;
        if (count >= top_n) {
            break;
        }
    }

    return 0;
}