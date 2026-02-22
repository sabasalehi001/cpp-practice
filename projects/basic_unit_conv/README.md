# Basic Unit Converter

This simple C++ program converts between various units of measurement:

*   Celsius to Fahrenheit and vice versa
*   Kilometers to Miles and vice versa
*   Kilograms to Pounds and vice versa

## Build Instructions

1.  Make sure you have CMake installed.
2.  Create a build directory:

    ```bash
    mkdir build
    cd build
    ```
3.  Run CMake:

    ```bash
    cmake ..
    ```
4.  Build the project:

    ```bash
    make
    ```

## Run Instructions

1.  Navigate to the build directory.
2.  Run the executable:

    ```bash
    ./app
    ```

The program will prompt you to select a conversion type and then enter the value to convert.

## Example Usage

```
Select conversion type:
1. Celsius to Fahrenheit
2. Fahrenheit to Celsius
3. Kilometers to Miles
4. Miles to Kilometers
5. Kilograms to Pounds
6. Pounds to Kilograms
Enter your choice (1-6): 1
Enter Celsius value: 25
25 Celsius is equal to 77 Fahrenheit
```