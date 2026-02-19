# Format Time Utility

This utility allows you to format a given timestamp according to a specified format string. It leverages the `std::chrono` library for time manipulation and `std::put_time` for formatting.

## Build Instructions

1.  Make sure you have a C++ compiler (like g++) and CMake installed.
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

Execute the compiled binary:

```bash
./app <timestamp> <format_string>
```

Where:

*   `<timestamp>` is the Unix timestamp (seconds since epoch).
*   `<format_string>` is the format string according to `std::put_time`. See [cppreference.com](https://en.cppreference.com/w/cpp/io/manip/put_time) for valid specifiers.

## Example Usage

To format the current timestamp as `YYYY-MM-DD HH:MM:SS`:

1.  Get the current timestamp (e.g., using `date +%s` on Linux).
2.  Run the utility:

    ```bash
    ./app $(date +%s) "%Y-%m-%d %H:%M:%S"
    ```

    This will output the current time formatted as `YYYY-MM-DD HH:MM:SS`.

Another example, to format as `Month Day, Year`:

```bash
./app $(date +%s) "%B %d, %Y"
```