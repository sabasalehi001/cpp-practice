# Text Analyzer

This project implements a simple word frequency counter that reads a text file, counts the occurrences of each word, and prints the top N most frequent words.

## Build Instructions

1.  Ensure you have CMake installed (version 3.10 or higher).
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
2.  Run the executable:
    ```bash
    ./app <input_file> <top_n>
    ```
    where `<input_file>` is the path to the text file you want to analyze, and `<top_n>` is the number of most frequent words you want to display.

## Example Usage

Suppose you have a file named `input.txt` with the following content:

```
the quick brown fox jumps over the lazy dog. the dog is lazy.
```

To find the top 3 most frequent words, run:

```bash
./app input.txt 3
```

The output will be similar to:

```
the: 3
lazy: 2
dog: 2
```