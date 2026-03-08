#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

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

  vector<unsigned char> buffer(16);
  streamsize bytes_read;

  while (file.read(reinterpret_cast<char*>(buffer.data()), buffer.size()) || (bytes_read = file.gcount()) > 0) {
    bytes_read = file.gcount();

    // Print hex representation
    for (streamsize i = 0; i < bytes_read; ++i) {
      cout << hex << setw(2) << setfill('0') << (int)buffer[i] << " ";
      if ((i + 1) % 8 == 0) {
        cout << " ";
      }
    }

    // Pad with spaces if less than 16 bytes were read
    for (streamsize i = bytes_read; i < 16; ++i) {
      cout << "   ";
      if ((i + 1) % 8 == 0) {
        cout << " ";
      }
    }

    cout << "|";

    // Print ASCII representation
    for (streamsize i = 0; i < bytes_read; ++i) {
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
