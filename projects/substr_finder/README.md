# Substring Finder

A simple command-line tool that searches for a substring within a file and prints the lines containing the substring along with their line numbers.

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

## Usage

```bash
./app <substring> <file_path>
```

For example:

```bash
./app "example" input.txt
```

This will search for the substring "example" in the file "input.txt" and print the matching lines with their line numbers to the console.

## Example input.txt

```
This is an example line.
Another line with the word example.
Just a regular line.
example at the beginning.
No match here.
```

## Example Output

```
1: This is an example line.
2: Another line with the word example.
4: example at the beginning.
```