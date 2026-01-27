#include <iostream>
#include <string>
#include <stack>

bool is_valid_json(const std::string& json_string) {
    std::stack<char> brace_stack;
    bool in_string = false;

    for (char c : json_string) {
        if (c == '"') {
            in_string = !in_string;
        } else if (!in_string) {
            if (c == '{') {
                brace_stack.push(c);
            } else if (c == '}') {
                if (brace_stack.empty() || brace_stack.top() != '{') {
                    return false;
                }
                brace_stack.pop();
            }
        }
    }

    return brace_stack.empty() && !in_string;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " \"json_string\"" << std::endl;
        return 1;
    }

    std::string json_string = argv[1];

    if (is_valid_json(json_string)) {
        std::cout << "Valid" << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }

    return 0;
}