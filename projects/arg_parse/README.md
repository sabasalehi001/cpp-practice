# arg_parse

A simple command-line argument parser in C++.

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

```bash
./app --help
./app -v 10 -n "My Name"
```

## Example

```bash
./app -v 42 -n "The Answer" --debug
```

This will parse the arguments and print the values.
