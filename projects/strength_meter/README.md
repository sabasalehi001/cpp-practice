# Password Strength Meter

This is a simple command-line tool to analyze the strength of a password.

## Building

```bash
mkdir build
cd build
cmake ..
make
```

## Running

```bash
./app <password>
```

## Example Usage

```bash
./app P@sswOrd123
```

This will output a strength score (0-100) and a brief assessment of the password's strength.
