# String Search

A simple command-line tool that searches for a substring within a file and prints matching lines with their line numbers.

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

```bash
./app <substring> <filename>
```

## Example Usage

Create a file named `test.txt` with the following content:

```
This is a test file.
It contains some lines of text.
This line has the word test in it.
Another line.
```

Now, run the string search tool:

```bash
./app test test.txt
```

Output:

```
3: This line has the word test in it.
```
