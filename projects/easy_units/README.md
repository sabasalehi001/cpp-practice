# Easy Units Converter

A simple command-line unit converter for temperature, distance, and weight.

## Build Instructions

1.  Make sure you have CMake and a C++ compiler (like g++) installed.
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

Execute the compiled binary:

```bash
./app
```

## Usage

The program accepts the following conversions:

*   **Temperature:**
    *   `c_to_f <celsius_value>`: Converts Celsius to Fahrenheit.
    *   `f_to_c <fahrenheit_value>`: Converts Fahrenheit to Celsius.
*   **Distance:**
    *   `km_to_mi <kilometers_value>`: Converts kilometers to miles.
    *   `mi_to_km <miles_value>`: Converts miles to kilometers.
*   **Weight:**
    *   `kg_to_lb <kilograms_value>`: Converts kilograms to pounds.
    *   `lb_to_kg <pounds_value>`: Converts pounds to kilograms.

## Example

To convert 25 degrees Celsius to Fahrenheit:

```bash
./app c_to_f 25
```

Output:

```
25 Celsius is equal to 77 Fahrenheit
```
