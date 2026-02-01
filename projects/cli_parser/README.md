# CLI Argument Parser

A simple command-line argument parser implemented in C++.

## Build Instructions

1.  Ensure you have CMake installed (version 3.15 or later).
2.  Clone the repository.
3.  Create a build directory:

    ```bash
    mkdir build
    cd build
    ```
4.  Configure the project using CMake:

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
    ./app [options]
    ```

## Example Usage

```bash
./app --name John --age 30 -v
```

This example will parse the following arguments:

*   `--name`: Value `John`
*   `--age`: Value `30`
*   `-v`: Flag present (verbose mode)
