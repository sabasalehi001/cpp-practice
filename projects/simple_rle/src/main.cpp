#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to compress a string using Run-Length Encoding
string compress(const string& input) {
    string compressed;
    if (input.empty()) {
        return compressed;
    }

    char current_char = input[0];
    int count = 1;

    for (size_t i = 1; i < input.length(); ++i) {
        if (input[i] == current_char) {
            count++;
        } else {
            compressed += to_string(count) + current_char;
            current_char = input[i];
            count = 1;
        }
    }

    // Add the last run to the compressed string
    compressed += to_string(count) + current_char;

    return compressed;
}

// Function to decompress a string compressed using Run-Length Encoding
string decompress(const string& input) {
    string decompressed;
    if (input.empty()) {
        return decompressed;
    }

    size_t i = 0;
    while (i < input.length()) {
        size_t num_end = i;
        while (num_end < input.length() && isdigit(input[num_end])){
            num_end++;
        }

        if (num_end == i){
            return "Error: Invalid compressed string.";
        }

        int count = stoi(input.substr(i, num_end - i));
        char character = input[num_end];

        for (int j = 0; j < count; ++j) {
            decompressed += character;
        }

        i = num_end + 1;
    }

    return decompressed;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_string>" << endl;
        return 1;
    }

    string input_string = argv[1];

    cout << "Original string: " << input_string << endl;

    string compressed_string = compress(input_string);
    cout << "Compressed string: " << compressed_string << endl;

    string decompressed_string = decompress(compressed_string);
    cout << "Decompressed string: " << decompressed_string << endl;

    return 0;
}