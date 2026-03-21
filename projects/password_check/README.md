# Password Strength Analyzer

This simple C++ project analyzes the strength of a password based on several criteria.

## Build Instructions

1.  Ensure you have a C++ compiler (like g++) and CMake installed.
2.  Clone the repository.
3.  Navigate to the project directory.
4.  Create a build directory:
   ```bash
   mkdir build
   cd build
   ```
5.  Run CMake:
   ```bash
   cmake ..
   ```
6.  Build the project:
   ```bash
   make
   ```

## Run Instructions

1.  Navigate to the `build` directory.
2.  Execute the compiled binary:
   ```bash
   ./app <password>
   ```
   Replace `<password>` with the password you want to analyze.

## Example Usage

```bash
./app P@sswOrd123
```

This will output a strength score for the provided password, along with feedback about its characteristics.
