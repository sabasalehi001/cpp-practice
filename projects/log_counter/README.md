# Log Counter

This simple C++ program analyzes a log file and counts the occurrences of `INFO`, `WARN`, and `ERROR` log levels.

## Build Instructions

1.  Make sure you have CMake installed (version 3.10 or higher).
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
2.  Run the executable `app` with the log file as an argument:

    ```bash
    ./app <log_file>
    ```
    Replace `<log_file>` with the actual path to your log file.

## Example Usage

Create a sample log file named `sample.log` with the following content:

```
INFO: Application started
WARN: Low disk space
ERROR: Failed to connect to database
INFO: User logged in
WARN: Invalid input
INFO: Data processed
ERROR: Critical error
```

Run the program:

```bash
./app sample.log
```

The output will be similar to:

```
INFO: 3
WARN: 2
ERROR: 2
```
