# Line Search

A simple command-line tool that searches for a substring within a file and prints the lines containing the substring along with their line numbers.

## Build Instructions

1.  Make sure you have CMake and a C++ compiler (e.g., GCC, Clang) installed.
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

```bash
./app <substring> <filename>
```

*   `<substring>`: The substring to search for.
*   `<filename>`: The name of the file to search in.

## Example Usage

Create a sample file named `example.txt` with the following content:

```
This is a test file.
It contains some sample text.
This line has the word test in it.
Another line.
```

Now, run the `line_search` tool to find lines containing the substring "test":

```bash
./app test example.txt
```

Expected Output:

```
1: This is a test file.
3: This line has the word test in it.
```