#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

struct Args {
    bool help = false;
    int verbose = 0;
    std::string name = "";
    bool debug = false;
};

void print_help() {
    std::cout << "Usage: app [options]\n"
              << "Options:\n"
              << "  -h, --help      Display this help message\n"
              << "  -v, --verbose <level>  Set verbose level (integer)\n"
              << "  -n, --name <name>     Set name (string)\n"
              << "  --debug           Enable debug mode\n"
              << std::endl;
}

Args parse_args(const std::vector<std::string>& args) {
    Args parsed_args;

    for (size_t i = 1; i < args.size(); ++i) {
        if (args[i] == "-h" || args[i] == "--help") {
            parsed_args.help = true;
            print_help();
            return parsed_args; // Exit early after displaying help
        } else if (args[i] == "-v" || args[i] == "--verbose") {
            if (i + 1 < args.size()) {
                try {
                    parsed_args.verbose = std::stoi(args[i + 1]);
                    ++i;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: Invalid verbose level: " << args[i + 1] << std::endl;
                    print_help();
                    exit(1);
                } catch (const std::out_of_range& e) {
                    std::cerr << "Error: Verbose level out of range: " << args[i + 1] << std::endl;
                    print_help();
                    exit(1);
                }
            } else {
                std::cerr << "Error: Missing verbose level\n";
                print_help();
                exit(1);
            }
        } else if (args[i] == "-n" || args[i] == "--name") {
            if (i + 1 < args.size()) {
                parsed_args.name = args[i + 1];
                ++i;
            } else {
                std::cerr << "Error: Missing name\n";
                print_help();
                exit(1);
            }
        } else if (args[i] == "--debug") {
            parsed_args.debug = true;
        } else {
            std::cerr << "Error: Unknown argument: " << args[i] << std::endl;
            print_help();
            exit(1);
        }
    }

    return parsed_args;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv + argc);

    Args parsed_args = parse_args(args);

    if(parsed_args.help) {
        return 0; // Exit after displaying help
    }

    std::cout << "Verbose level: " << parsed_args.verbose << std::endl;
    std::cout << "Name: " << parsed_args.name << std::endl;
    std::cout << "Debug mode: " << (parsed_args.debug ? "enabled" : "disabled") << std::endl;

    return 0;
}