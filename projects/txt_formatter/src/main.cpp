#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string wrapText(const string& text, int width) {
    stringstream wrapped;
    stringstream currentLine;
    istringstream wordStream(text);
    string word;

    while (wordStream >> word) {
        if (static_cast<int>(currentLine.str().length() + word.length() + (currentLine.str().empty() ? 0 : 1)) <= width) {
            if (!currentLine.str().empty()) {
                currentLine << " ";
            }
            currentLine << word;
        } else {
            wrapped << currentLine.str() << endl;
            currentLine.str(string()); // Clear the stringstream
            currentLine << word;
        }
    }

    wrapped << currentLine.str();
    return wrapped.str();
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        cerr << "Usage: " << argv[0] << " <column_width> [input_file]" << endl;
        return 1;
    }

    int width = stoi(argv[1]);
    if (width <= 0) {
        cerr << "Column width must be a positive integer." << endl;
        return 1;
    }

    string text;
    if (argc == 3) {
        // Read from file
        ifstream inputFile(argv[2]);
        if (!inputFile.is_open()) {
            cerr << "Error opening file: " << argv[2] << endl;
            return 1;
        }
        stringstream buffer;
        buffer << inputFile.rdbuf();
        text = buffer.str();
        inputFile.close();
    } else {
        // Read from stdin
        stringstream buffer;
        string line;
        while (getline(cin, line)) {
            buffer << line << endl;
        }
        text = buffer.str();
    }

    cout << wrapText(text, width) << endl;

    return 0;
}