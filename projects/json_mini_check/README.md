# json_mini_check

A simple JSON validator that checks for balanced braces and properly closed quotes.

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Run

```bash
./app "{\"name\": \"John Doe\", \"age\": 30}"
./app "{\"name\": \"John Doe\", \"age\": 30"  # Missing closing brace
./app "{\"name\": \"John Doe\", \"age\": 30\"" # Unbalanced quotes
```

The program will print "Valid" if the JSON is valid, and "Invalid" otherwise.