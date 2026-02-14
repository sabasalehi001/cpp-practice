# Password Strength Analyzer

This simple C++ program analyzes the strength of a password based on several criteria: length, presence of uppercase letters, lowercase letters, digits, and special characters.

## Build Instructions

1.  Make sure you have CMake installed (version 3.15 or higher).
2.  Create a build directory:

    ```bash
    mkdir build
    cd build
    ```
3.  Run CMake to generate the build files:

    ```bash
    cmake ..
    ```
4.  Build the project:

    ```bash
    make
    ```

## Run Instructions

1.  Navigate to the build directory where the executable `app` was created.
2.  Run the executable:

    ```bash
    ./app <password>
    ```

    Replace `<password>` with the password you want to analyze.

## Example Usage

```bash
./app P@sswOrd123
```

This will output the strength analysis of the password "P@sswOrd123".
