# Log Inspector

A simple C++ program that analyzes a log file and counts the occurrences of INFO, WARN, and ERROR messages.

## Build Instructions

1.  Make sure you have CMake installed.
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
2.  Run the executable with the log file as an argument:

    ```bash
    ./app <log_file>
    ```

    Replace `<log_file>` with the path to your log file.

## Example Usage

Create a sample log file named `example.log` with the following content:

```
INFO: Starting application
WARN: Configuration file not found
ERROR: Failed to connect to database
INFO: User logged in
INFO: Data processed successfully
WARN: Low disk space
ERROR: Null pointer exception
INFO: Shutting down
```

Run the program:

```bash
./app example.log
```

The output will be similar to:

```
INFO: 4
WARN: 2
ERROR: 2
```