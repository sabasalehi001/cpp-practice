# CLI Options Parser

This is a simple command-line argument parser that supports flags (options without values) and options with values.

## Build Instructions

1.  Make sure you have CMake installed (version 3.10 or higher).
2.  Create a build directory:
    ```bash
    mkdir build
    cd build
    ```
3.  Run CMake to generate the build files:
    ```bash
    cmake ..
    ```
4.  Build the project:
    ```bash
    make
    ```

## Run Instructions

1.  Navigate to the `build` directory.
2.  Run the executable `app`.

## Example Usage

```bash
./app --help
./app --input file.txt --output results.txt --verbose
./app -i input.txt -o output.txt
./app --count 10
```
