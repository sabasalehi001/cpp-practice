# Task Tracker

A simple command-line todo list application with file persistence.

## Features

*   Add tasks
*   List tasks
*   Mark tasks as done
*   Tasks are saved to a file and loaded on startup.

## Build Instructions

1.  Make sure you have CMake and a C++ compiler (e.g., GCC, Clang) installed.
2.  Clone the repository.
3.  Create a `build` directory:
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

1.  Navigate to the `build` directory.
2.  Run the executable:
    ```bash
    ./app
    ```

## Usage

```
./app add "Buy groceries"
./app add "Clean the house"
./app list
./app done 1
./app list
```

The task list is stored in `tasks.txt` in the same directory as the executable.
