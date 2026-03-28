# clippie

A simple command-line argument parser library in C++.

## Building

```bash
mkdir build
cd build
cmake ..
make
```

## Running

```bash
./app --help
./app -n "My Name" -a 42
./app --verbose -f input.txt
```

## Example Usage

This simple program parses command-line arguments. It supports flags (like `--verbose`) and arguments with values (like `-n "My Name"`).
