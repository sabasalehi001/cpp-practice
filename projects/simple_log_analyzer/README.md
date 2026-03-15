# Simple Log Analyzer

This is a simple C++ program that analyzes a log file and counts the number of INFO, WARN, and ERROR entries.

## Build Instructions

1.  Make sure you have CMake and a C++ compiler (like g++) installed.
2.  Clone the repository.
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

## Run Instructions

1.  Navigate to the build directory.
2.  Run the executable, providing the log file as an argument:

    ```bash
    ./app <log_file>
    ```

    Replace `<log_file>` with the path to your log file.

## Example Usage

Suppose you have a log file named `example.log` with the following content:

```
2023-10-27 10:00:00 INFO: Application started
2023-10-27 10:00:01 WARN:  Low disk space
2023-10-27 10:00:02 INFO: Processing data
2023-10-27 10:00:03 ERROR: Failed to connect to database
2023-10-27 10:00:04 INFO: Application ended
2023-10-27 10:00:05 WARN:  High CPU usage
2023-10-27 10:00:06 ERROR: Null pointer exception
```

Running the analyzer:

```bash
./app example.log
```

The output will be:

```
INFO: 3
WARN: 2
ERROR: 2
```