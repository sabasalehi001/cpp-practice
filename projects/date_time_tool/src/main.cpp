#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <format_string>" << std::endl;
        return 1;
    }

    std::string format_string = argv[1];

    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_c);

    std::stringstream ss;
    ss << std::put_time(&now_tm, format_string.c_str());
    std::cout << ss.str() << std::endl;

    return 0;
}