# Date/Time Formatter Utility

This is a simple command-line utility to format date and time according to a specified format string.

## Build Instructions

1.  Make sure you have CMake and a C++ compiler (e.g., g++) installed.
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
    ./app <format_string> <timestamp>
    ```
    where:
    *   `<format_string>` is the format string (see C++ `std::strftime` for valid specifiers).
    *   `<timestamp>` is the Unix timestamp (seconds since epoch).

## Example Usage

To format the timestamp `1678886400` (March 15, 2023 00:00:00 UTC) as "Year-Month-Day":

```bash
./app "%Y-%m-%d" 1678886400
```

Output:

```
2023-03-15
```

To format the timestamp as "Hour:Minute:Second":

```bash
./app "%H:%M:%S" 1678886400
```

Output:

```
00:00:00
```