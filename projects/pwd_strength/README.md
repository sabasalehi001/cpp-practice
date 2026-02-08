# Password Strength Analyzer

This simple C++ program analyzes the strength of a given password based on several criteria:

*   Length
*   Presence of uppercase letters
*   Presence of lowercase letters
*   Presence of digits
*   Presence of special characters

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

This will output a strength score (e.g., "Password Strength: Strong").
