#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

double celsius_to_fahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double f) {
    return (f - 32.0) * 5.0 / 9.0;
}

double kilometers_to_miles(double km) {
    return km * 0.621371;
}

double miles_to_kilometers(double mi) {
    return mi * 1.60934;
}

double kilograms_to_pounds(double kg) {
    return kg * 2.20462;
}

double pounds_to_kilograms(double lb) {
    return lb * 0.453592;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <value> <input_unit> <output_unit>" << endl;
        return 1;
    }

    double value;
    string input_unit;
    string output_unit;

    try {
        value = stod(argv[1]);
        input_unit = argv[2];
        output_unit = argv[3];
    } catch (const invalid_argument& e) {
        cerr << "Invalid input: " << e.what() << endl;
        return 1;
    }

    double result;

    if (input_unit == "C" && output_unit == "F") {
        result = celsius_to_fahrenheit(value);
    } else if (input_unit == "F" && output_unit == "C") {
        result = fahrenheit_to_celsius(value);
    } else if (input_unit == "km" && output_unit == "mi") {
        result = kilometers_to_miles(value);
    } else if (input_unit == "mi" && output_unit == "km") {
        result = miles_to_kilometers(value);
    } else if (input_unit == "kg" && output_unit == "lb") {
        result = kilograms_to_pounds(value);
    } else if (input_unit == "lb" && output_unit == "kg") {
        result = pounds_to_kilograms(value);
    } else {
        cerr << "Unsupported conversion." << endl;
        return 1;
    }

    cout << fixed << setprecision(2) << result << endl;

    return 0;
}