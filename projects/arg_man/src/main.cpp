#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

// Function to display help message
void printHelp() {
    cout << "Usage: app [options]" << endl;
    cout << "Options:" << endl;
    cout << "  --help                 Display this help message" << endl;
    cout << "  --input <file>       Specify the input file" << endl;
    cout << "  --output <file>      Specify the output file" << endl;
    cout << "  --verbose              Enable verbose mode" << endl;
    cout << "  -i <file>            Short form for --input" << endl;
    cout << "  -o <file>            Short form for --output" << endl;
    cout << "  -v                   Short form for --verbose" << endl;
    cout << "  --name <string>        Specify a name" << endl;
    cout << "  --age <int>            Specify an age" << endl;
}

// Function to parse command-line arguments
map<string, string> parseArguments(int argc, char* argv[]) {
    map<string, string> arguments;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];

        if (arg == "--help") {
            arguments["help"] = "true";
            printHelp();
            exit(0);
        } else if (arg == "--input" || arg == "-i") {
            if (i + 1 < argc) {
                arguments["input"] = argv[i + 1];
                ++i;
            } else {
                cerr << "Error: Missing argument for " << arg << endl;
                exit(1);
            }
        } else if (arg == "--output" || arg == "-o") {
            if (i + 1 < argc) {
                arguments["output"] = argv[i + 1];
                ++i;
            } else {
                cerr << "Error: Missing argument for " << arg << endl;
                exit(1);
            }
        } else if (arg == "--verbose" || arg == "-v") {
            arguments["verbose"] = "true";
        } else if (arg == "--name") {
            if (i + 1 < argc) {
                arguments["name"] = argv[i + 1];
                ++i;
            } else {
                cerr << "Error: Missing argument for " << arg << endl;
                exit(1);
            }
        } else if (arg == "--age") {
            if (i + 1 < argc) {
                arguments["age"] = argv[i + 1];
                ++i;
            } else {
                cerr << "Error: Missing argument for " << arg << endl;
                exit(1);
            }
        } else {
            cerr << "Error: Unknown argument: " << arg << endl;
            printHelp();
            exit(1);
        }
    }

    return arguments;
}

int main(int argc, char* argv[]) {
    map<string, string> args = parseArguments(argc, argv);

    // Example usage of parsed arguments
    if (args.count("input")) {
        cout << "Input file: " << args["input"] << endl;
    }
    if (args.count("output")) {
        cout << "Output file: " << args["output"] << endl;
    }
    if (args.count("verbose") && args["verbose"] == "true") {
        cout << "Verbose mode enabled." << endl;
    }
    if (args.count("name")) {
        cout << "Name: " << args["name"] << endl;
    }
    if (args.count("age")) {
        cout << "Age: " << args["age"] << endl;
    }

    return 0;
}
