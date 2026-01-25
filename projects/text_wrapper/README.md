# Text Wrapper

A simple command-line tool to wrap text to a specified column width.

## Build Instructions

1.  Make sure you have CMake installed (version 3.10 or later).
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

```bash
./app <column_width> [input_file]
```

*   `<column_width>`:  The maximum column width for the wrapped text (an integer).
*   `[input_file]`:  Optional. The path to the input text file. If not provided, the program reads from standard input.

## Example Usage

**From standard input:**

```bash
echo "This is a long line of text that needs to be wrapped to a specific column width." | ./app 20
```

**From a file:**

```bash
./app 30 input.txt
```

Where `input.txt` contains:

```
This is another long line of text that will be wrapped based on the column width provided.
```