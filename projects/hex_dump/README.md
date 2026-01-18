# hex_dump

A simple hex viewer that prints the bytes of a file in hexadecimal and ASCII.

## Build Instructions

1.  Ensure you have CMake and a C++ compiler (like g++) installed.
2.  Clone the repository or download the source code.
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
2.  Run the executable `app` with the file you want to view as an argument:

    ```bash
    ./app <filename>
    ```

    For example:

    ```bash
    ./app example.txt
    ```

## Example Usage

Create a file named `example.txt` with the following content:

```
Hello, world!
This is a test.
```

Run the hex_dump:

```bash
./app example.txt
```

Expected output:

```
00000000: 48 65 6c 6c 6f 2c 20 77 6f 72 6c 64 21 0a 54 68  Hello, world!.Th
00000010: 69 73 20 69 73 20 61 20 74 65 73 74 2e 0a        is is a test..
```