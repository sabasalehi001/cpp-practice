# Time Styler

A simple command-line utility to format date and time.

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
    ./app [format_string]
    ```
    If no format string is provided, the default format `%Y-%m-%d %H:%M:%S` is used.

## Example Usage

```bash
./app "%d/%m/%Y %I:%M:%S %p"
```

This will output the current date and time formatted as `DD/MM/YYYY HH:MM:SS AM/PM` (e.g., `20/07/2024 03:30:00 PM`).

```bash
./app "%a, %d %b %Y %H:%M:%S %Z"
```
This will output the current date and time formatted as `Sat, 20 Jul 2024 15:30:00 UTC` (or the appropriate timezone).

## Supported Format Specifiers (from strftime):

*   `%a`: Abbreviated weekday name
*   `%A`: Full weekday name
*   `%b`: Abbreviated month name
*   `%B`: Full month name
*   `%c`: Date and time representation appropriate for locale
*   `%d`: Day of month as a decimal number (01-31)
*   `%H`: Hour in 24-hour format (00-23)
*   `%I`: Hour in 12-hour format (01-12)
*   `%j`: Day of year as a decimal number (001-366)
*   `%m`: Month as a decimal number (01-12)
*   `%M`: Minute as a decimal number (00-59)
*   `%p`: AM or PM designation
*   `%S`: Second as a decimal number (00-60)
*   `%U`: Week number of the year (Sunday as the first day of the week) as a decimal number (00-53)
*   `%w`: Weekday as a decimal number (0-6, Sunday is 0)
*   `%W`: Week number of the year (Monday as the first day of the week) as a decimal number (00-53)
*   `%x`: Date representation appropriate for locale
*   `%X`: Time representation appropriate for locale
*   `%y`: Year without century as a decimal number (00-99)
*   `%Y`: Year with century as a decimal number
*   `%Z`: Time zone name
*   `%%`: A literal `%` character