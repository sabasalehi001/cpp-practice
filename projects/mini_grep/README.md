# Mini Grep

A simple implementation of grep (substring search with line numbers) in C++.

## Build Instructions

1.  Make sure you have CMake installed (version 3.10 or higher).
2.  Create a build directory:
    ```bash
    mkdir build
    cd build
    ```
3.  Run CMake to generate the build files:
    ```bash
    cmake ..
    ```
4.  Build the project using your system's build tool (e.g., make):
    ```bash
    make
    ```

## Run Instructions

```bash
./app <substring> <filename>
```

`<substring>` is the string you want to search for.
`<filename>` is the name of the file to search in.

## Example Usage

To search for the word "example" in the file "input.txt", run:

```bash
./app example input.txt
```

This will print each line in `input.txt` that contains the word "example", along with its line number.
