# Password Strength Analyzer

This simple C++ program analyzes the strength of a password based on several factors, including length, character diversity, and the presence of uppercase letters, lowercase letters, numbers, and special characters.

## Building

1.  Make sure you have a C++ compiler (like g++) and CMake installed.
2.  Clone this repository.
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

## Running

1.  Navigate to the build directory.
2.  Run the executable:

    ```bash
    ./app
    ```

The program will prompt you to enter a password.  It will then output a strength rating.

## Example Usage

```bash
./app
```

**Input:**
```
Password: Password123!
```

**Output:**
```
Password Strength: Strong
```