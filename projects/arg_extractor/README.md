# ArgExtractor

A simple command-line argument parser that supports flags and values.

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Run

```bash
./app --help
./app --name John --age 30 -v
```

## Example Usage

The example program parses the following arguments:

*   `--help`: Displays help information.
*   `--name <value>`: Specifies a name (string value).
*   `--age <value>`: Specifies an age (integer value).
*   `-v`:  Verbose flag (no value).

If `--name` is not specified, it defaults to "World". If `--age` is not specified, the program does not print age information. The `-v` flag enables verbose output.
