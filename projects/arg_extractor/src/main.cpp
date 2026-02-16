#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct ParsedArgs {
    bool help = false;
    string name = "World";
    int age = -1;
    bool verbose = false;
};

ParsedArgs parseArgs(int argc, char* argv[]) {
    ParsedArgs args;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];

        if (arg == "--help") {
            args.help = true;
        } else if (arg == "--name") {
            if (i + 1 < argc) {
                args.name = argv[i + 1];
                ++i;
            } else {
                cerr << "Error: --name requires a value.\n";
            }
        } else if (arg == "--age") {
            if (i + 1 < argc) {
                try {
                    args.age = stoi(argv[i + 1]);
                    ++i;
                } catch (const invalid_argument& e) {
                    cerr << "Error: --age requires an integer value.\n";
                } catch (const out_of_range& e) {
                    cerr << "Error: --age value out of range.\n";
                }
            } else {
                cerr << "Error: --age requires a value.\n";
            }
        } else if (arg == "-v") {
            args.verbose = true;
        } else {
            cerr << "Error: Unknown argument: " << arg << endl;
        }
    }

    return args;
}

int main(int argc, char* argv[]) {
    ParsedArgs args = parseArgs(argc, argv);

    if (args.help) {
        cout << "Usage: app [options]\n"
             << "Options:\n"
             << "  --help        Display this help message\n"
             << "  --name <value>  Specify a name\n"
             << "  --age <value>   Specify an age\n"
             << "  -v            Enable verbose output\n";
        return 0;
    }

    if (args.verbose) {
        cout << "Verbose mode enabled.\n";
    }

    cout << "Hello, " << args.name << "!\n";

    if (args.age != -1) {
        cout << "Age: " << args.age << endl;
    }

    return 0;
}