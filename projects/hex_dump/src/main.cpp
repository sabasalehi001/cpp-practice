#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    ifstream file(argv[1], ios::binary);

    if (!file.is_open()) {
        cerr << "Error opening file: " << argv[1] << endl;
        return 1;
    }

    const int bytes_per_line = 16;
    unsigned long address = 0;

    while (file.peek() != EOF) {
        cout << setw(8) << setfill('0') << hex << address << ": ";

        // Read and print bytes in hex
        for (int i = 0; i < bytes_per_line; ++i) {
            if (file.peek() != EOF) {
                unsigned char byte = file.get();
                cout << setw(2) << setfill('0') << hex << (int)byte << " ";
            } else {
                cout << "   "; // Padding for incomplete lines
            }
        }

        cout << " ";

        file.seekg(-bytes_per_line, ios::cur); // Go back to start of line to read chars

        // Read and print bytes in ASCII
        for (int i = 0; i < bytes_per_line; ++i) {
            if (file.peek() != EOF) {
                unsigned char byte = file.get();
                if (byte >= 32 && byte <= 126) {
                    cout << byte;
                } else {
                    cout << ".";
                }
            } else {
                break; // Stop printing ASCII for padding
            }
        }
        cout << endl;
        address += bytes_per_line;
    }

    file.close();
    return 0;
}