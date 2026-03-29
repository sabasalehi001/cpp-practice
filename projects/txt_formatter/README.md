# Text Wrap Formatter

A simple command-line tool to wrap text to a specified column width.

## Build Instructions

1.  Make sure you have CMake installed (version 3.15 or later).
2.  Clone the repository.
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
2.  Run the executable:

    ```bash
    ./app <column_width> [input_file]
    ```

    -   `<column_width>`: The desired column width (an integer).
    -   `[input_file]`: (Optional) The input file. If not provided, reads from standard input.

## Example Usage

```bash
# Wrap text from stdin to 40 columns
echo "This is a long line of text that needs to be wrapped to a specific column width." | ./app 40

# Wrap text from a file to 60 columns
./app 60 input.txt
```

Where `input.txt` contains:

```
This is another long line of text in a file.  It also needs to be wrapped.
This is the second line of text in the file.
```