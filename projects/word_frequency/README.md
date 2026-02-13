# Word Frequency Counter

This project is a simple C++ program that counts the frequency of words in a text file and displays the top N most frequent words.

## Building

1.  Make sure you have CMake installed.
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

## Running

```bash
./app <input_file> <N>
```

*   `<input_file>`: The path to the text file to analyze.
*   `<N>`: The number of top words to display.

## Example Usage

Create a sample text file named `example.txt` with the following content:

```text
the quick brown fox jumps over the lazy dog
the fox is quick
```

Run the program to display the top 3 most frequent words:

```bash
./app example.txt 3
```

Expected Output:

```
the: 3
fox: 2
quick: 2
```