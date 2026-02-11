# Hex Display

A simple command-line tool to display the contents of a file in hexadecimal and ASCII format.

## Build Instructions

1.  Ensure you have CMake and a C++ compiler (e.g., g++) installed.
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

1.  Navigate to the build directory.
2.  Execute the `app` executable, providing the file you want to view as a command-line argument:

    ```bash
    ./app <file_path>
    ```

    Replace `<file_path>` with the actual path to the file.

## Example Usage

To view the contents of a file named `example.txt`, run:

```bash
./app example.txt
```

The output will be a hexadecimal representation of the file contents, along with the corresponding ASCII characters, if printable.
