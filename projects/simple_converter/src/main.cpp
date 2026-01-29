#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Function to convert Celsius to Fahrenheit
double c2f(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double f2c(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to convert Kilometers to Miles
double km2mi(double kilometers) {
    return kilometers * 0.621371;
}

// Function to convert Miles to Kilometers
double mi2km(double miles) {
    return miles * 1.60934;
}

// Function to convert Kilograms to Pounds
double kg2lb(double kilograms) {
    return kilograms * 2.20462;
}

// Function to convert Pounds to Kilograms
double lb2kg(double pounds) {
    return pounds * 0.453592;
}

int main() {
    string input;
    cout << "Enter conversion (e.g., c2f 25, km2mi 10, lb2kg 150): ";
    getline(cin, input);

    stringstream ss(input);
    string command;
    double value;

    ss >> command >> value;

    cout << fixed << setprecision(2);

    if (command == "c2f") {
        cout << value << " Celsius = " << c2f(value) << " Fahrenheit" << endl;
    } else if (command == "f2c") {
        cout << value << " Fahrenheit = " << f2c(value) << " Celsius" << endl;
    } else if (command == "km2mi") {
        cout << value << " Kilometers = " << km2mi(value) << " Miles" << endl;
    } else if (command == "mi2km") {
        cout << value << " Miles = " << mi2km(value) << " Kilometers" << endl;
    } else if (command == "kg2lb") {
        cout << value << " Kilograms = " << kg2lb(value) << " Pounds" << endl;
    } else if (command == "lb2kg") {
        cout << value << " Pounds = " << lb2kg(value) << " Kilograms" << endl;
    } else {
        cout << "Invalid conversion command." << endl;
    }

    return 0;
}
