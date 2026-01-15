# Run-Length Encoding Compressor

This project implements a simple run-length encoding (RLE) compressor and decompressor in C++.

## Build Instructions

1.  Make sure you have CMake installed.
2.  Clone the repository.
3.  Create a build directory:

    ```bash
    mkdir build
    cd build
    ```
4.  Run CMake:

    ```bash
    cmake ..
    ```
5.  Build the project:

    ```bash
    make
    ```

## Run Instructions

1.  Navigate to the build directory.
2.  Run the executable:

    ```bash
    ./app <input_string>
    ```

    Replace `<input_string>` with the string you want to compress and decompress.

## Example Usage

```bash
./app "AAABBCDDDDE"
```

This will output:

```
Original string: AAABBCDDDDE
Compressed string: 3A2B1C4D1E
Decompressed string: AAABBCDDDDE
```