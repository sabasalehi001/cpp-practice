#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <optional>

class ArgParser {
public:
    ArgParser(int argc, char** argv) : argc_(argc), argv_(argv) {}

    bool has_flag(const std::string& flag) const {
        return std::any_of(argv_ + 1, argv_ + argc_, [&](const char* arg) {
            return std::string(arg) == flag;
        });
    }

    std::optional<std::string> get_value(const std::string& flag) const {
        for (int i = 1; i < argc_; ++i) {
            if (std::string(argv_[i]) == flag) {
                if (i + 1 < argc_) {
                    return std::string(argv_[i + 1]);
                } else {
                    return std::nullopt; // Flag found, but no value provided.
                }
            }
        }
        return std::nullopt; // Flag not found.
    }

    void print_help() const {
        std::cout << "Usage: app [options]\n"
                  << "Options:\n"
                  << "  -n, --name <name>  Sets the name.\n"
                  << "  -a, --age <age>    Sets the age.\n"
                  << "  -v, --verbose      Enables verbose mode.\n"
                  << "  -f, --file <file>  Specifies an input file.\n"
                  << "  -h, --help         Displays this help message.\n"
                  << std::endl;
    }

private:
    int argc_;
    char** argv_;
};

int main(int argc, char** argv) {
    ArgParser parser(argc, argv);

    if (parser.has_flag("--help") || parser.has_flag("-h")) {
        parser.print_help();
        return 0;
    }

    if (parser.has_flag("--verbose") || parser.has_flag("-v")) {
        std::cout << "Verbose mode enabled.\n";
    }

    if (auto name = parser.get_value("--name")) {
        std::cout << "Name: " << *name << std::endl;
    } else if (auto name = parser.get_value("-n")) {
      std::cout << "Name: " << *name << std::endl;
    }

    if (auto age_str = parser.get_value("--age")) {
        try {
            int age = std::stoi(*age_str);
            std::cout << "Age: " << age << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid age provided.\n";
        }
    } else if (auto age_str = parser.get_value("-a")) {
        try {
            int age = std::stoi(*age_str);
            std::cout << "Age: " << age << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid age provided.\n";
        }
    }

    if (auto filename = parser.get_value("--file")) {
        std::cout << "Filename: " << *filename << std::endl;
    } else if (auto filename = parser.get_value("-f")){
        std::cout << "Filename: " << *filename << std::endl;
    }

    return 0;
}