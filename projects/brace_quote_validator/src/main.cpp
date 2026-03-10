#include <iostream>
#include <string>
#include <stack>

bool isValidJson(const std::string& jsonString) {
    std::stack<char> braces;
    bool inString = false;

    for (char c : jsonString) {
        if (c == '"') {
            inString = !inString;
        } else if (!inString) {
            if (c == '{') {
                braces.push(c);
            } else if (c == '}') {
                if (braces.empty()) {
                    return false; // Unmatched closing brace
                }
                braces.pop();
            }
        }
    }

    return braces.empty() && !inString; // Check for unmatched opening braces and unclosed quotes
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " \"<json_string>\"" << std::endl;
        return 1;
    }

    std::string jsonString = argv[1];

    if (isValidJson(jsonString)) {
        std::cout << "Valid" << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }

    return 0;
}