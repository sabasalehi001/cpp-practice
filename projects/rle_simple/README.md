# Simple Run-Length Encoding Compressor

This project implements a basic run-length encoding (RLE) compressor and decompressor in C++.

## Build Instructions

1.  Make sure you have CMake and a C++ compiler (like g++) installed.
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

1.  The executable will be located in the `build` directory.  Run it with:

    ```bash
    ./app <command> <input_string>
    ```

    where:
    *   `<command>` is either `compress` or `decompress`
    *   `<input_string>` is the string to compress or decompress.

## Example Usage

To compress the string "AAABBBCCCDD":

```bash
./app compress AAABBBCCCDD
```

Output:

```
Compressed: 3A3B3C2D
```

To decompress the string "3A3B3C2D":

```bash
./app decompress 3A3B3C2D
```

Output:

```
Decompressed: AAABBBCCCDD
```
