# Simple Unit Converter

A command-line unit converter for common units.

## Supported Conversions:

*   Celsius to Fahrenheit and Fahrenheit to Celsius
*   Kilometers to Miles and Miles to Kilometers
*   Kilograms to Pounds and Pounds to Kilograms

## Building

1.  Make sure you have CMake installed.
2.  Create a build directory:
    ```bash
    mkdir build
    cd build
    ```
3.  Configure the project:
    ```bash
    cmake ..
    ```
4.  Build the project:
    ```bash
    make
    ```

## Running

Execute the compiled binary:

```bash
./app
```

## Usage

The program takes three arguments: value, input unit, output unit.

Example:

```bash
./app 25 C F
```
This will convert 25 degrees Celsius to Fahrenheit.

```bash
./app 100 km mi
```
This will convert 100 kilometers to miles.

```bash
./app 70 kg lb
```
This will convert 70 kilograms to pounds.

Valid units:

*   C: Celsius
*   F: Fahrenheit
*   km: Kilometers
*   mi: Miles
*   kg: Kilograms
*   lb: Pounds