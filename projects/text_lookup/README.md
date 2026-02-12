# text_lookup

A simple command-line tool to search for a substring within a file and print matching lines along with their line numbers.

## Build Instructions

1.  Make sure you have CMake and a C++ compiler (e.g., GCC, Clang) installed.
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

## Usage

```bash
./app <substring> <filename>
```

Example:

```bash
./app "example" input.txt
```

This will search for the substring "example" in the file `input.txt` and print each matching line along with its line number to the console.

## Example `input.txt`

```
This is an example line.
Another line with the word example.
Yet another line.
This line contains example twice example.
No match here.
```

Running the example command above would produce output similar to:

```
1: This is an example line.
2: Another line with the word example.
4: This line contains example twice example.
```