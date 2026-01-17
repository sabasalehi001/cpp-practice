# Unit Converter

A simple command-line unit converter written in C++.

## Supported Conversions:

*   Celsius to Fahrenheit
*   Fahrenheit to Celsius
*   Kilometers to Miles
*   Miles to Kilometers
*   Kilograms to Pounds
*   Pounds to Kilograms

## Building

1.  Make sure you have CMake installed.
2.  Clone the repository.
3.  Create a build directory:
    ```bash
    mkdir build
    cd build
    ```
4.  Run CMake:
    ```bash
    cmake ..
    ```
5.  Build the project:
    ```bash
    make
    ```

## Running

Execute the compiled binary:

```bash
./app
```

The program will prompt you to select a conversion type and enter the value to convert.

## Example Usage

```
Choose conversion type:
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