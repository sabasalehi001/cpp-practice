# arg_man

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
./app --input my_file.txt --output output.txt --verbose
./app -i input.txt -o output.txt -v
```

## Example

The following command:

```bash
./app --name John --age 30 -v
```

Would parse the following arguments:

*   `name`: John
*   `age`: 30
*   `verbose`: true
