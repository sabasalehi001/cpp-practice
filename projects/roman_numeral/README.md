# Roman Numeral Converter

A simple C++ program that converts integers to Roman numerals.

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
    ./app <integer>
    ```
    Replace `<integer>` with the integer you want to convert.

## Example Usage

To convert the number 42 to a Roman numeral:

```bash
./app 42
```

Output:

```
XLII
```