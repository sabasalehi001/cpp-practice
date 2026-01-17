#include <iostream>
#include <iomanip>

using namespace std;

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double kilometers_to_miles(double kilometers) {
    return kilometers * 0.621371;
}

double miles_to_kilometers(double miles) {
    return miles * 1.60934;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}

double pounds_to_kilograms(double pounds) {
    return pounds * 0.453592;
}

int main() {
    int choice;
    double value;

    cout << "Choose conversion type:" << endl;
    cout << "1. Celsius to Fahrenheit" << endl;
    cout << "2. Fahrenheit to Celsius" << endl;
    cout << "3. Kilometers to Miles" << endl;
    cout << "4. Miles to Kilometers" << endl;
    cout << "5. Kilograms to Pounds" << endl;
    cout << "6. Pounds to Kilograms" << endl;
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    cout << "Enter value: ";
    cin >> value;

    cout << fixed << setprecision(2);

    switch (choice) {
        case 1:
            cout << value << " Celsius is equal to " << celsius_to_fahrenheit(value) << " Fahrenheit" << endl;
            break;
        case 2:
            cout << value << " Fahrenheit is equal to " << fahrenheit_to_celsius(value) << " Celsius" << endl;
            break;
        case 3:
            cout << value << " Kilometers is equal to " << kilometers_to_miles(value) << " Miles" << endl;
            break;
        case 4:
            cout << value << " Miles is equal to " << miles_to_kilometers(value) << " Kilometers" << endl;
            break;
        case 5:
            cout << value << " Kilograms is equal to " << kilograms_to_pounds(value) << " Pounds" << endl;
            break;
        case 6:
            cout << value << " Pounds is equal to " << pounds_to_kilograms(value) << " Kilograms" << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}