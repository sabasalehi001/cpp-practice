# Simple Tasks

A simple todo list application with file persistence.

## Build Instructions

1.  Make sure you have CMake and a C++ compiler (like g++) installed.
2.  Clone the repository.
3.  Navigate to the project directory.
4.  Create a `build` directory:

    ```bash
    mkdir build
    cd build
    ```
5.  Run CMake:

    ```bash
    cmake ..
    ```
6.  Build the project:

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

The application uses a `tasks.txt` file in the same directory to store the tasks. If the file does not exist, it will be created.

Commands:

*   `add <task>`: Adds a new task to the list.
*   `list`: Lists all tasks with their status.
*   `done <task_number>`: Marks a task as done.
*   `exit`: Exits the application.

### Example

```
add Buy groceries
add Walk the dog
list
```

Output:

```
1. [ ] Buy groceries
2. [ ] Walk the dog
```

```
done 1
list
```

Output:

```
1. [x] Buy groceries
2. [ ] Walk the dog
```