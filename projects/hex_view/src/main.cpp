#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <file_path>" << endl;
    return 1;
  }

  string file_path = argv[1];
  ifstream file(file_path, ios::binary);

  if (!file.is_open()) {
    cerr << "Error opening file: " << file_path << endl;
    return 1;
  }

  const int bytes_per_line = 16;
  unsigned long address = 0;

  while (file.peek() != EOF) {
    cout << setfill('0') << setw(8) << hex << address << ": ";

    // Read and print hex bytes
    for (int i = 0; i < bytes_per_line; ++i) {
      if (file.peek() != EOF) {
        unsigned char byte = file.get();
        cout << setfill('0') << setw(2) << hex << (int)byte << " ";
      } else {
        cout << "   "; // Padding for incomplete lines
      }

      if (i == 7) {
        cout << " "; // Extra space after 8 bytes
      }
    }

    cout << "|";

    // Rewind the last line
    file.seekg(-bytes_per_line, ios::cur);

    // Print ASCII representation
    for (int i = 0; i < bytes_per_line; ++i) {
      if (file.peek() != EOF) {
        unsigned char byte = file.get();
        if (byte >= 32 && byte <= 126) {
          cout << byte;
        } else {
          cout << ".";
        }
      } else {
        break;
      }
    }

    cout << "|" << endl;

    address += bytes_per_line;
    file.seekg(address); // Seek to the next line
  }

  file.close();
  return 0;
}