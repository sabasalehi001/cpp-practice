#include <iostream>
#include <string>
#include <stack>

bool is_valid_json(const std::string& json_string) {
    std::stack<char> bracket_stack;
    bool in_string = false;

    for (char c : json_string) {
        if (c == '"') {
            in_string = !in_string;
        } else if (in_string) {
            continue; // Ignore characters inside strings
        }

        if (c == '{') {
            bracket_stack.push(c);
        } else if (c == '}') {
            if (bracket_stack.empty() || bracket_stack.top() != '{') {
                return false;
            }
            bracket_stack.pop();
        }
    }

    return bracket_stack.empty() && !in_string;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <json_string>" << std::endl;
        return 1;
    }

    std::string json_string = argv[1];

    if (is_valid_json(json_string)) {
        std::cout << "Valid JSON" << std::endl;
    } else {
        std::cout << "Invalid JSON" << std::endl;
    }

    return 0;
}