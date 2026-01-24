# Roman Numeral Converter

This project provides a simple command-line tool to convert integers to Roman numerals.

## Build Instructions

1.  Make sure you have CMake and a C++ compiler (like g++) installed.
2.  Clone the repository.
3.  Navigate to the project directory.
4.  Create a build directory:

    ```bash
    mkdir build
    cd build
    ```
5.  Run CMake:

    ```bash
    cmake ..
    ```
6.  Build the project:

    ```bash
    make
    ```

## Run Instructions

1.  Navigate to the `build` directory.
2.  Run the executable:

    ```bash
    ./app <integer>
    ```

    Replace `<integer>` with the integer you want to convert (e.g., `./app 1984`). The program will print the Roman numeral representation to the console.

## Example Usage

```bash
./app 2023
```

Output:

```
MMXXIII
```