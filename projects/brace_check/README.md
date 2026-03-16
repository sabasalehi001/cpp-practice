# Brace Check

A simple C++ program that validates a tiny subset of JSON for correctly balanced braces and quotes.

## Build Instructions

1.  Make sure you have CMake installed (version 3.15 or later).
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

1.  After building, the executable `app` will be located in the `build` directory.
2.  Run the program by providing the JSON string as a command-line argument:

    ```bash
    ./app '{"key": "value"}'
    ```

## Example Usage

```bash
./app '{"name": "John", "age": 30}'
```

This will output "Valid JSON" if the braces and quotes are balanced and correctly nested. Otherwise, it will output "Invalid JSON".

```bash
./app '{"name": "John", "age": 30'  # Missing closing brace
```

This will output "Invalid JSON".

```bash
./app '{ "key": "value" }'
```
This will output "Valid JSON".
