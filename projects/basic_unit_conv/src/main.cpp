#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to convert Kilometers to Miles
double kilometersToMiles(double kilometers) {
    return kilometers * 0.621371;
}

// Function to convert Miles to Kilometers
double milesToKilometers(double miles) {
    return miles * 1.60934;
}

// Function to convert Kilograms to Pounds
double kilogramsToPounds(double kilograms) {
    return kilograms * 2.20462;
}

// Function to convert Pounds to Kilograms
double poundsToKilograms(double pounds) {
    return pounds * 0.453592;
}

int main() {
    int choice;
    double value;

    cout << "Select conversion type:" << endl;
    cout << "1. Celsius to Fahrenheit" << endl;
    cout << "2. Fahrenheit to Celsius" << endl;
    cout << "3. Kilometers to Miles" << endl;
    cout << "4. Miles to Kilometers" << endl;
    cout << "5. Kilograms to Pounds" << endl;
    cout << "6. Pounds to Kilograms" << endl;
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    // Input validation for the choice
    if (cin.fail() || choice < 1 || choice > 6) {
        cerr << "Invalid input. Please enter a number between 1 and 6." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 1;
    }

    cout << "Enter value: ";
    cin >> value;

    // Input validation for the value
    if (cin.fail()) {
        cerr << "Invalid input. Please enter a number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 1;
    }

    cout << fixed << setprecision(2);

    switch (choice) {
        case 1:
            cout << value << " Celsius is equal to " << celsiusToFahrenheit(value) << " Fahrenheit" << endl;
            break;
        case 2:
            cout << value << " Fahrenheit is equal to " << fahrenheitToCelsius(value) << " Celsius" << endl;
            break;
        case 3:
            cout << value << " Kilometers is equal to " << kilometersToMiles(value) << " Miles" << endl;
            break;
        case 4:
            cout << value << " Miles is equal to " << milesToKilometers(value) << " Kilometers" << endl;
            break;
        case 5:
            cout << value << " Kilograms is equal to " << kilogramsToPounds(value) << " Pounds" << endl;
            break;
        case 6:
            cout << value << " Pounds is equal to " << poundsToKilograms(value) << " Kilograms" << endl;
            break;
        default:
            cerr << "Invalid choice." << endl;
            return 1;
    }

    return 0;
}