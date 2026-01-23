# Simple Run-Length Encoding (RLE) Compressor

This project implements a basic Run-Length Encoding (RLE) compressor and decompressor in C++.

## Build Instructions

1.  Make sure you have CMake and a C++ compiler (e.g., GCC) installed.
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
    ./app <input_string>
    ```
    Replace `<input_string>` with the string you want to compress and decompress.  The program will output the compressed and decompressed strings to the console.

## Example Usage

To compress and decompress the string "AAABBBCCDAA", run:

```bash
./app AAABBBCCDAA
```

The output will be:

```
Original string: AAABBBCCDAA
Compressed string: 3A3B2C1D2A
Decompressed string: AAABBBCCDAA
```