#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string wrap_text(const string& text, int column_width) {
    stringstream wrapped_text;
    stringstream current_line;
    stringstream word;

    for (char c : text) {
        if (isspace(c)) {
            if (current_line.tellp() + word.tellp() + 1 <= column_width) {
                current_line << word.str() << c;
            } else {
                wrapped_text << current_line.str() << endl;
                current_line.str(string()); // Clear the current line
                current_line << word.str() << c;
            }
            word.str(string()); // Clear the word
        } else {
            word << c;
        }
    }

    // Handle the last word, if any
    if (word.tellp() > 0) {
        if (current_line.tellp() + word.tellp() <= column_width) {
            current_line << word.str();
        } else {
            wrapped_text << current_line.str() << endl;
            current_line.str(string());
            current_line << word.str();
        }
    }

    wrapped_text << current_line.str();
    return wrapped_text.str();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <column_width> [input_file]" << endl;
        return 1;
    }

    int column_width;
    try {
        column_width = stoi(argv[1]);
        if (column_width <= 0) {
            cerr << "Column width must be a positive integer." << endl;
            return 1;
        }
    } catch (const invalid_argument& e) {
        cerr << "Invalid column width: " << argv[1] << endl;
        return 1;
    }

    string text;
    if (argc > 2) {
        // Read from file
        ifstream file(argv[2]);
        if (!file.is_open()) {
            cerr << "Error opening file: " << argv[2] << endl;
            return 1;
        }
        stringstream buffer;
        buffer << file.rdbuf();
        text = buffer.str();
        file.close();
    } else {
        // Read from stdin
        stringstream buffer;
        buffer << cin.rdbuf();
        text = buffer.str();
    }

    cout << wrap_text(text, column_width) << endl;

    return 0;
}