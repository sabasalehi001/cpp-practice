# Password Strength Analyzer

This project provides a simple command-line tool to analyze the strength of a password.

## Building

1.  Ensure you have CMake and a C++ compiler (e.g., g++) installed.
2.  Navigate to the project directory.
3.  Create a build directory:

    ```bash
    mkdir build
    cd build
    ```

4.  Run CMake:

    ```bash
    cmake ..
    ```

5.  Build the project:

    ```bash
    make
    ```

## Running

Execute the compiled binary with the password as an argument:

```bash
./app <password>
```

For example:

```bash
./app MyStrongPassword123!
```

This will output a strength score and a short assessment of the password's quality.

## Strength Criteria

*   **Length:** Longer passwords are generally stronger.
*   **Character Variety:** Using a mix of uppercase, lowercase, numbers, and symbols improves strength.
*   **Common Words:** Avoid using common words or patterns.
