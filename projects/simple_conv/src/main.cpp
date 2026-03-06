#include <iostream>
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

// Function to convert kilometers to miles
double kilometersToMiles(double kilometers) {
    return kilometers * 0.621371;
}

// Function to convert miles to kilometers
double milesToKilometers(double miles) {
    return miles * 1.60934;
}

// Function to convert kilograms to pounds
double kilogramsToPounds(double kilograms) {
    return kilograms * 2.20462;
}

// Function to convert pounds to kilograms
double poundsToKilograms(double pounds) {
    return pounds * 0.453592;
}

int main() {
    int choice;
    double value;

    cout << "Choose conversion type:\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "3. Kilometers to Miles\n";
    cout << "4. Miles to Kilometers\n";
    cout << "5. Kilograms to Pounds\n";
    cout << "6. Pounds to Kilograms\n";
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    cout << fixed << setprecision(2);

    switch (choice) {
        case 1:
            cout << "Enter Celsius temperature: ";
            cin >> value;
            cout << value << " Celsius is equal to " << celsiusToFahrenheit(value) << " Fahrenheit" << endl;
            break;
        case 2:
            cout << "Enter Fahrenheit temperature: ";
            cin >> value;
            cout << value << " Fahrenheit is equal to " << fahrenheitToCelsius(value) << " Celsius" << endl;
            break;
        case 3:
            cout << "Enter kilometers: ";
            cin >> value;
            cout << value << " Kilometers is equal to " << kilometersToMiles(value) << " Miles" << endl;
            break;
        case 4:
            cout << "Enter miles: ";
            cin >> value;
            cout << value << " Miles is equal to " << milesToKilometers(value) << " Kilometers" << endl;
            break;
        case 5:
            cout << "Enter kilograms: ";
            cin >> value;
            cout << value << " Kilograms is equal to " << kilogramsToPounds(value) << " Pounds" << endl;
            break;
        case 6:
            cout << "Enter pounds: ";
            cin >> value;
            cout << value << " Pounds is equal to " << poundsToKilograms(value) << " Kilograms" << endl;
            break;
        default:
            cout << "Invalid choice.\n";
    }

    return 0;
}