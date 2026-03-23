#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to convert a string to lowercase
string toLowercase(const string& str) {
    string result = "";
    for (char c : str) {
        result += tolower(c);
    }
    return result;
}

// Function to clean a word by removing punctuation
string cleanWord(const string& word) {
    string result = "";
    for (char c : word) {
        if (isalnum(c)) {
            result += c;
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <top_n>" << endl;
        return 1;
    }

    string input_file = argv[1];
    int top_n = stoi(argv[2]);

    ifstream file(input_file);
    if (!file.is_open()) {
        cerr << "Error opening file: " << input_file << endl;
        return 1;
    }

    map<string, int> word_counts;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            string cleaned_word = cleanWord(toLowercase(word));
            if (!cleaned_word.empty()) {
                word_counts[cleaned_word]++;
            }
        }
    }

    file.close();

    // Sort words by frequency in descending order
    vector<pair<string, int>> sorted_words(word_counts.begin(), word_counts.end());
    sort(sorted_words.begin(), sorted_words.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Print the top N most frequent words
    int count = 0;
    for (const auto& pair : sorted_words) {
        cout << pair.first << ": " << pair.second << endl;
        count++;
        if (count >= top_n) {
            break;
        }
    }

    return 0;
}