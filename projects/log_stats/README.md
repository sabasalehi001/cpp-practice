# Log Stats

This simple C++ project analyzes a log file and counts the occurrences of `INFO`, `WARN`, and `ERROR` log levels.

## Build Instructions

1.  Make sure you have CMake and a C++ compiler (like g++) installed.
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

1.  After building, you'll find an executable named `app` in the `build` directory.
2.  Run the program, providing the path to your log file as a command-line argument:
    ```bash
    ./app <path_to_log_file>
    ```

## Example Usage

Suppose you have a log file named `example.log` with the following content:

```
2023-10-27 10:00:00 INFO: System started.
2023-10-27 10:00:05 WARN: Low disk space.
2023-10-27 10:00:10 INFO: User logged in.
2023-10-27 10:00:15 ERROR: Connection timeout.
2023-10-27 10:00:20 INFO: Data processed.
2023-10-27 10:00:25 WARN: High CPU usage.
2023-10-27 10:00:30 ERROR: File not found.
```

Running the program would produce the following output:

```
INFO: 3
WARN: 2
ERROR: 2
```