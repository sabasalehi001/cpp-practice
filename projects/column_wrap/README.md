# Column Wrap

A simple command-line tool to wrap text to a specified column width.

## Build Instructions

1.  Ensure you have CMake and a C++ compiler (e.g., g++) installed.
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
./app <column_width> [input_file]
```

*   `<column_width>`: The desired column width (an integer).
*   `[input_file]`: Optional. The path to the input text file. If not provided, the program reads from standard input.

**Example:**

To wrap the contents of `input.txt` to 80 columns:

```bash
./app 80 input.txt
```

To wrap text from standard input to 60 columns:

```bash
echo "This is a very long line of text that needs to be wrapped to 60 columns." | ./app 60
```