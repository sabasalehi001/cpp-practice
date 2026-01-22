# Run-Length Encoding Tool

This project implements a simple run-length encoding (RLE) compressor and decompressor.

## Build Instructions

1.  Make sure you have CMake installed (version 3.10 or higher).
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

```bash
./app -c "AAAABBBCCDAA"
./app -d "4A3B2C1D2A"
```

## Example Usage

Compressing the string "AAAABBBCCDAA":

```bash
./app -c "AAAABBBCCDAA"
```

Output:

```
4A3B2C1D2A
```

Decompressing the string "4A3B2C1D2A":

```bash
./app -d "4A3B2C1D2A"
```

Output:

```
AAAABBBCCDAA
```