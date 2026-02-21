# File Word Frequency Counter

This project implements a simple file word frequency counter in C++. It reads a text file, counts the occurrences of each word, and outputs the top N most frequent words.

## Building

```bash
mkdir build
cd build
cmake ..
make
```

## Running

```bash
./app <input_file> <N>
```

*   `<input_file>`: The path to the input text file.
*   `<N>`: The number of top words to display.

## Example Usage

Create a file named `example.txt` with the following content:

```text
The quick brown fox jumps over the lazy dog. The dog is lazy.
```

Run the program:

```bash
./app example.txt 3
```

Expected output:

```
The: 2
dog: 2
lazy: 2
```