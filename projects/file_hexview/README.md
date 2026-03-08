# File Hex Viewer

This simple C++ project provides a command-line tool to display the contents of a file in hexadecimal and ASCII format.

## Build Instructions

1.  Make sure you have CMake and a C++ compiler (e.g., g++) installed.
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
2.  Run the executable, providing the file path as an argument:

    ```bash
    ./app <file_path>
    ```
    Replace `<file_path>` with the path to the file you want to view.

## Example Usage

To view the contents of a file named `example.txt`:

```bash
./app example.txt
```

This will print the hexadecimal representation and ASCII interpretation of each byte in the file to the console.
