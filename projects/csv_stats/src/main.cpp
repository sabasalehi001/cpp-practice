#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <numeric>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <csv_file_path> <column_index>" << std::endl;
        return 1;
    }

    std::string csv_file_path = argv[1];
    int column_index;
    try {
        column_index = std::stoi(argv[2]);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid column index: " << argv[2] << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "Column index out of range: " << argv[2] << std::endl;
        return 1;
    }

    std::ifstream file(csv_file_path);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << csv_file_path << std::endl;
        return 1;
    }

    std::string line;
    std::vector<double> values;
    bool first_line = true;
    while (std::getline(file, line)) {
        if (first_line) {
            first_line = false;
            continue; // Skip header row
        }

        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        if (column_index < 0 || column_index >= row.size()) {
            std::cerr << "Column index out of range. Row size: " << row.size() << ", Index: " << column_index << std::endl;
            return 1;
        }

        try {
            double value = std::stod(row[column_index]);
            values.push_back(value);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Non-numeric value found in column " << column_index << ": " << row[column_index] << std::endl;
            return 1;
        } catch (const std::out_of_range& e) {
            std::cerr << "Value out of range in column " << column_index << ": " << row[column_index] << std::endl;
            return 1;
        }
    }

    if (values.empty()) {
        std::cerr << "No numeric data found in the specified column." << std::endl;
        return 1;
    }

    double min_value = std::numeric_limits<double>::max();
    double max_value = std::numeric_limits<double>::lowest();
    double sum = 0.0;

    for (double value : values) {
        min_value = std::min(min_value, value);
        max_value = std::max(max_value, value);
        sum += value;
    }

    double mean = sum / values.size();

    std::cout << "Min: " << min_value << std::endl;
    std::cout << "Max: " << max_value << std::endl;
    std::cout << "Mean: " << mean << std::endl;

    return 0;
}