# hex_view

A simple command-line tool to view files in hexadecimal format, along with ASCII representation.

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

```bash
./app <file_path>
```

Example:

```bash
./app example.txt
```

This will print the contents of `example.txt` in hexadecimal and ASCII format to the console.

Example `example.txt` file:

```text
Hello, world!
This is a test.
```

Example Output (truncated):

```
00000000: 48 65 6c 6c 6f 2c 20 77 6f 72 6c 64 21 0a 54 68 Hello, world!.Th
00000010: 69 73 20 69 73 20 61 20 74 65 73 74 2e 0a       is is a test..
```