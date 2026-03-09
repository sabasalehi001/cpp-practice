#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Temperature Conversions
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Distance Conversions
double kilometers_to_miles(double kilometers) {
    return kilometers * 0.621371;
}

double miles_to_kilometers(double miles) {
    return miles * 1.60934;
}

// Weight Conversions
double kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}

double pounds_to_kilograms(double pounds) {
    return pounds * 0.453592;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: ./app <conversion_type> <value>" << endl;
        cerr << "Example: ./app c_to_f 25" << endl;
        return 1;
    }

    string conversion_type = argv[1];
    double value;

    try {
        value = stod(argv[2]);
    } catch (const invalid_argument& e) {
        cerr << "Invalid input: " << argv[2] << " is not a valid number." << endl;
        return 1;
    }

    cout << fixed << setprecision(2);

    if (conversion_type == "c_to_f") {
        cout << value << " Celsius is equal to " << celsius_to_fahrenheit(value) << " Fahrenheit" << endl;
    } else if (conversion_type == "f_to_c") {
        cout << value << " Fahrenheit is equal to " << fahrenheit_to_celsius(value) << " Celsius" << endl;
    } else if (conversion_type == "km_to_mi") {
        cout << value << " Kilometers is equal to " << kilometers_to_miles(value) << " Miles" << endl;
    } else if (conversion_type == "mi_to_km") {
        cout << value << " Miles is equal to " << miles_to_kilometers(value) << " Kilometers" << endl;
    } else if (conversion_type == "kg_to_lb") {
        cout << value << " Kilograms is equal to " << kilograms_to_pounds(value) << " Pounds" << endl;
    } else if (conversion_type == "lb_to_kg") {
        cout << value << " Pounds is equal to " << pounds_to_kilograms(value) << " Kilograms" << endl;
    } else {
        cerr << "Invalid conversion type: " << conversion_type << endl;
        return 1;
    }

    return 0;
}
