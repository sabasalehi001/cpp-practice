#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string wrap_text(const string& text, int width) {
    stringstream wrapped_text;
    stringstream current_line;

    stringstream input_stream(text);
    string word;

    while (input_stream >> word) {
        if (current_line.tellp() == 0) {
            if (word.length() > width) {
                string first_part = word.substr(0, width);
                string second_part = word.substr(width);

                wrapped_text << first_part << endl;
                current_line.str("");
                current_line << second_part << " ";
            } else {
                current_line << word << " ";
            }
        } else {
            if (current_line.tellp() + word.length() > width) {
                wrapped_text << current_line.str().substr(0, current_line.str().length() - 1) << endl; // Remove trailing space
                current_line.str("");
                if (word.length() > width) {
                    string first_part = word.substr(0, width);
                    string second_part = word.substr(width);

                    wrapped_text << first_part << endl;
                    current_line.str("");
                    current_line << second_part << " ";
                } else {
                    current_line << word << " ";
                }
            } else {
                current_line << word << " ";
            }
        }
    }

    if (current_line.tellp() > 0) {
        wrapped_text << current_line.str().substr(0, current_line.str().length() - 1) << endl; // Remove trailing space
    }

    return wrapped_text.str();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <column_width> [input_file]" << endl;
        return 1;
    }

    int column_width = stoi(argv[1]);
    if (column_width <= 0) {
        cerr << "Column width must be a positive integer." << endl;
        return 1;
    }

    string input_text;

    if (argc > 2) {
        // Read from file
        ifstream input_file(argv[2]);
        if (!input_file.is_open()) {
            cerr << "Error opening file: " << argv[2] << endl;
            return 1;
        }

        stringstream buffer;
        buffer << input_file.rdbuf();
        input_text = buffer.str();
        input_file.close();
    } else {
        // Read from stdin
        stringstream buffer;
        buffer << cin.rdbuf();
        input_text = buffer.str();
    }

    string wrapped_text = wrap_text(input_text, column_width);
    cout << wrapped_text;

    return 0;
}