# Date Time Tool

A simple command-line utility for formatting date and time.

## Build Instructions

1.  Make sure you have CMake installed.
2.  Create a build directory:

    ```bash
    mkdir build
    cd build
    ```
3.  Run CMake:

    ```bash
    cmake ..
    ```
4.  Build the project:

    ```bash
    make
    ```

## Usage

```bash
./app <format_string>
```

Where `<format_string>` is a string that specifies the desired date/time format.

Supported format specifiers:

*   `%Y`: Year (e.g., 2023)
*   `%m`: Month (01-12)
*   `%d`: Day (01-31)
*   `%H`: Hour (00-23)
*   `%M`: Minute (00-59)
*   `%S`: Second (00-59)

### Example:

```bash
./app "%Y-%m-%d %H:%M:%S"
```

This will output the current date and time in the format "YYYY-MM-DD HH:MM:SS".
