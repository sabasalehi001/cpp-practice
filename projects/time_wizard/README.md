# Time Wizard

A simple date/time formatting utility.

## Build Instructions

1.  Ensure you have CMake and a C++ compiler (e.g., g++) installed.
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

## Run Instructions

1.  Navigate to the build directory.
2.  Run the executable:
    ```bash
    ./app
    ```

## Example Usage

The program takes a format string as a command-line argument.  If no argument is provided, it uses a default format.

Example:

```bash
./app "%Y-%m-%d %H:%M:%S"
```

This will output the current date and time formatted as `YYYY-MM-DD HH:MM:SS`.

Another Example:

```bash
./app "%a, %d %b %Y %I:%M %p"
```

This will output the current date and time formatted as `Weekday, DD Month YYYY HH:MM AM/PM`.

See `man strftime` or a similar resource for format specifier options.
