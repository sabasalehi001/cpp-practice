# csv_stats

A simple command-line tool to calculate the minimum, maximum, and mean of a specified numeric column in a CSV file.

## Build Instructions

1.  Ensure you have CMake installed (version 3.10 or later).
2.  Clone the repository.
3.  Create a build directory:

    ```bash
    mkdir build
    cd build
    ```
4.  Configure the project using CMake:

    ```bash
    cmake ..
    ```
5.  Build the project:

    ```bash
    make
    ```

## Run Instructions

1.  Navigate to the `build` directory.
2.  Execute the `csv_stats` application, providing the CSV file path and the column index as arguments:

    ```bash
    ./app <csv_file_path> <column_index>
    ```

    *   `<csv_file_path>`:  The path to your CSV file.
    *   `<column_index>`: The zero-based index of the numeric column to analyze.  (e.g., `0` for the first column, `1` for the second, etc.)

## Example Usage

Assume you have a CSV file named `data.csv` with the following content:

```csv
Name,Age,City
Alice,30,New York
Bob,25,London
Charlie,35,Paris
```

To calculate the statistics for the 'Age' column (column index 1), run:

```bash
./app data.csv 1
```

This will output:

```
Min: 25
Max: 35
Mean: 30
```

## Error Handling

The application provides basic error handling for file opening, column index out of range, and non-numeric data in the specified column.  It will print error messages to the console if any of these issues occur.