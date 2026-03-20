# Word Counter

A simple C++ program that counts the frequency of words in a file and prints the top N most frequent words.

## Build Instructions

1.  Make sure you have CMake installed (version 3.15 or higher).
2.  Clone the repository.
3.  Navigate to the project directory.
4.  Create a build directory:

    ```bash
    mkdir build
    cd build
    ```
5.  Run CMake:

    ```bash
    cmake ..
    ```
6.  Build the project:

    ```bash
    make
    ```

## Run Instructions

```bash
./app <input_file> <top_n>
```

*   `<input_file>`: The path to the input text file.
*   `<top_n>`: The number of most frequent words to display.

## Example Usage

Create a sample text file named `input.txt` with the following content:

```text
The quick brown fox jumps over the lazy fox.
The quick brown fox.
```

Run the program:

```bash
./app input.txt 3
```

Expected output (order may vary):

```
fox: 3
the: 3
brown: 2
```
