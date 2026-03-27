#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct ParsedArgs {
    bool help = false;
    string input_file;
    string output_file;
    bool verbose = false;
    int count = 0;
};

ParsedArgs parse_arguments(int argc, char* argv[]) {
    ParsedArgs args;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];

        if (arg == "--help") {
            args.help = true;
        } else if (arg == "--input" || arg == "-i") {
            if (i + 1 < argc) {
                args.input_file = argv[i + 1];
                ++i;
            } else {
                cerr << "Error: --input requires a value." << endl;
            }
        } else if (arg == "--output" || arg == "-o") {
            if (i + 1 < argc) {
                args.output_file = argv[i + 1];
                ++i;
            } else {
                cerr << "Error: --output requires a value." << endl;
            }
        } else if (arg == "--verbose") {
            args.verbose = true;
        } else if (arg == "--count") {
            if (i + 1 < argc) {
                try {
                    args.count = stoi(argv[i + 1]);
                    ++i;
                } catch (const invalid_argument& e) {
                    cerr << "Error: --count requires an integer value." << endl;
                } catch (const out_of_range& e) {
                    cerr << "Error: --count value is out of range." << endl;
                }
            } else {
                cerr << "Error: --count requires a value." << endl;
            }
        } else {
            cerr << "Error: Unknown option: " << arg << endl;
        }
    }

    return args;
}

int main(int argc, char* argv[]) {
    ParsedArgs args = parse_arguments(argc, argv);

    if (args.help) {
        cout << "Usage: app [options]\n"
             << "Options:\n"
             << "  --help           Display this help message\n"
             << "  --input <file>   Specify the input file\n"
             << "  --output <file>  Specify the output file\n"
             << "  --verbose        Enable verbose mode\n"
             << "  --count <number> Specify a count value\n" << endl;
        return 0;
    }

    cout << "Input file: " << args.input_file << endl;
    cout << "Output file: " << args.output_file << endl;
    cout << "Verbose: " << (args.verbose ? "true" : "false") << endl;
    cout << "Count: " << args.count << endl;

    return 0;
}
