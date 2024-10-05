# C++ Vector Implementation

This project is a custom implementation of a C++ vector, showcasing my growth in coding, memory management, and functional programming. The project is well-documented with comments explaining the code and is designed to demonstrate my expertise in managing dynamic memory, implementing core vector functions, and writing clean, readable code.

## Project Structure

The repository consists of the following files:

- **main.cpp**: Contains the main driver function for testing the vector implementation and validating various functionalities.
- **vector.hpp**: Header file containing the `Vector` class definition, method declarations, and supporting iterator class.
- **main.exe**: Compiled executable for testing the vector implementation on Windows platforms.
- **README.md**: Documentation file explaining the project structure, setup, and usage instructions.

## Features

- **Custom Vector Class**: Implements a dynamic array-like structure, similar to `std::vector` in C++.
- **Memory Management**: Demonstrates expertise in managing heap memory, ensuring proper allocation, deallocation, and resizing.
- **Functional Methods**: Includes key methods such as:
  - `push_back()`: Adds an element to the end of the vector.
  - `pop_back()`: Removes the last element.
  - `resize()`: Changes the vector size, adjusting memory as needed.
  - `shrink_to_fit()`: Reduces the memory footprint by freeing unused capacity.
  - `operator[]`: Overloads the subscript operator to allow easy access to elements.
  - `capacity()`: Returns the current capacity of the vector.
  - `size()`: Returns the number of elements in the vector.
  - `erase()`: Removes elements from a specified range.
  - `at()`: Safely accesses an element at a given index, with bounds checking.
- **Extensive Comments**: The code includes comments explaining the purpose and functionality of each part, making it easy to understand the logic and thought process behind the implementation.

## Technologies

- **C++**: The core language used for implementing the vector class and managing dynamic memory.
- **Windows Executable**: The project includes a compiled executable (`main.exe`) for running the program on Windows platforms.

## Setup and Compilation

### Prerequisites

- C++ compiler (e.g., GCC, Clang, or MSVC)
- Windows (for the provided executable) or any platform with a C++ compiler

### To Compile the Source Code:

1. Clone the repository:

    ```bash
    git clone https://github.com/Jorstors/Vector-Implementation
    ```

2. Navigate to the project directory:

    ```bash
    cd Vector-Implementation
    ```

3. Compile the `main.cpp` file along with `vector.hpp`:

    ```bash
    g++ main.cpp -o main
    ```

4. Run the executable (Linux/macOS):

    ```bash
    ./main
    ```

5. Or, on Windows:

    ```bash
    main.exe
    ```

## Usage

The program tests the custom vector class by performing various operations such as adding, removing, and accessing elements. The results are printed to the console, demonstrating the functionality and correctness of the implementation.

### Example Run

The provided `main.cpp` file tests the following operations:

- Constructing vectors using different constructors.
- Adding elements using `push_back()`.
- Removing elements with `pop_back()` and `erase()`.
- Accessing elements with `operator[]` and `at()`.
- Shrinking the vector with `shrink_to_fit()`.
- Printing the vector size and capacity to validate dynamic memory management.

Modify the `main.cpp` file to add custom tests as needed.

## Comments and Documentation

- Every function is thoroughly documented with comments explaining the logic, memory management decisions, and how each method contributes to the overall functionality of the vector.
- This serves as a learning tool for anyone interested in C++ dynamic memory and custom container implementation.

## Key Learning Areas

- **Dynamic Memory Management**: Learned how to properly allocate, resize, and deallocate memory using pointers in C++.
- **Operator Overloading**: Implemented custom operators (e.g., `[]`,`==`, `*` ) to improve the operabillity of the vector and iterator classes.
- **Functionality**: Implemented core functions that allow the vector to handle variable-size arrays efficiently, mimicking the behavior of `std::vector`.

### License

This project is licensed under the ISC License:

Copyright (c) 2024, Justus Jones

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

---

Made by [Justus Jones](https://github.com/Jorstors)

