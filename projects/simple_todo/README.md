# Simple Todo List

A simple command-line todo list application with file persistence.

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

```bash
./app add "Buy groceries"
./app add "Walk the dog"
./app list
./app done 1
./app list
```

## Commands

*   `add <task>`: Adds a new task to the list.
*   `list`: Lists all tasks with their status (pending or done).
*   `done <index>`: Marks the task at the given index as done (index starts from 1).
