#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file_path>" << endl;
        return 1;
    }

    string file_path = argv[1];
    ifstream file(file_path, ios::binary);

    if (!file.is_open()) {
        cerr << "Error: Could not open file '" << file_path << "'" << endl;
        return 1;
    }

    const int bytes_per_line = 16;
    unsigned char buffer[bytes_per_line];
    streamsize bytes_read;

    while (file.read(reinterpret_cast<char*>(buffer), bytes_per_line) || file.gcount() > 0) {
        bytes_read = file.gcount();

        // Print hexadecimal representation
        for (int i = 0; i < bytes_read; ++i) {
            cout << hex << setw(2) << setfill('0') << (int)buffer[i] << " ";
            if ((i + 1) % 8 == 0) {
                cout << " "; // Extra space after every 8 bytes
            }
        }

        // Pad with spaces if less than bytes_per_line were read
        for (int i = bytes_read; i < bytes_per_line; ++i) {
            cout << "   ";
            if ((i + 1) % 8 == 0) {
                cout << " ";
            }
        }

        cout << "|";

        // Print ASCII representation
        for (int i = 0; i < bytes_read; ++i) {
            if (isprint(buffer[i])) {
                cout << buffer[i];
            } else {
                cout << ".";
            }
        }

        cout << "|" << endl;
    }

    file.close();
    return 0;
}