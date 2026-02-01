#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct ParsedArgs {
    std::vector<std::string> positional_args;
    std::unordered_map<std::string, std::string> named_args;
    std::unordered_map<std::string, bool> flags;
};

ParsedArgs parse_arguments(int argc, char* argv[]) {
    ParsedArgs parsed_args;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg.rfind("--", 0) == 0) { // Long option
            std::string name = arg.substr(2);
            if (i + 1 < argc) {
                std::string next_arg = argv[i + 1];
                if (next_arg.rfind("--", 0) != 0 && next_arg.rfind("-", 0) != 0) {
                    parsed_args.named_args[name] = next_arg;
                    ++i;
                } else {
                    parsed_args.flags[name] = true; // Flag without value
                }
            } else {
                parsed_args.flags[name] = true; // Flag without value
            }
        } else if (arg.rfind("-", 0) == 0) { // Short option
            std::string name = arg.substr(1);
            parsed_args.flags[name] = true;
        } else { // Positional argument
            parsed_args.positional_args.push_back(arg);
        }
    }

    return parsed_args;
}

int main(int argc, char* argv[]) {
    ParsedArgs args = parse_arguments(argc, argv);

    std::cout << "Positional Arguments:" << std::endl;
    for (const auto& arg : args.positional_args) {
        std::cout << "  " << arg << std::endl;
    }

    std::cout << "Named Arguments:" << std::endl;
    for (const auto& [name, value] : args.named_args) {
        std::cout << "  " << name << ": " << value << std::endl;
    }

    std::cout << "Flags:" << std::endl;
    for (const auto& [name, present] : args.flags) {
        std::cout << "  " << name << std::endl;
    }

    return 0;
}