# BraceQuoteValidator

A simple C++ program that validates a tiny subset of JSON syntax, checking for balanced braces and properly closed quotes.

## Building

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

## Running

Execute the built binary:

```bash
./app "{\"key\": \"value\"}"
```

This will output `Valid` or `Invalid` based on the input JSON string.

## Example Usage

Valid JSON:

```bash
./app "{\"name\": \"John Doe\", \"age\": 30}"
```

Invalid JSON (unbalanced brace):

```bash
./app "{\"name\": \"John Doe\", \"age\": 30"
```

Invalid JSON (unclosed quote):

```bash
./app "{\"name\": \"John Doe, \"age\": 30}"
```