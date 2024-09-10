# C++ Vector Implementation

This project is a custom implementation of a C++ vector, showcasing my growth in coding, memory management, and functional programming. The project is well-documented with comments explaining the code and is designed to demonstrate my expertise in managing dynamic memory, implementing core vector functions, and writing clean, readable code.

## Project Structure

- **vector.cpp**: The main C++ source file containing the vector implementation and the associated functions.
- **vector.exe**: Compiled executable for testing the vector implementation (Windows).

## Features

- **Custom Vector Class**: Implements a dynamic array-like structure, similar to `std::vector` in C++.
- **Memory Management**: Demonstrates expertise in managing heap memory, ensuring proper allocation, deallocation, and resizing.
- **Functional Methods**: Includes key methods such as:
  - `push_back()`: Adds an element to the end of the vector.
  - `pop_back()`: Removes the last element.
  - `resize()`: Changes the vector size, adjusting memory as needed.
  - `operator[]`: Overloads the subscript operator to allow easy access to elements.
  - `capacity()`: Returns the current capacity of the vector.
  - `size()`: Returns the number of elements in the vector.
- **Extensive Comments**: The code includes comments explaining the purpose and functionality of each part, making it easy to understand the logic and thought process behind the implementation.

## Technologies

- **C++**: The core language used for implementing the vector class and managing dynamic memory.
- **Windows Executable**: The project includes a compiled executable (`.exe`) for running the program on Windows platforms.

## Setup and Compilation

### Prerequisites
- C++ compiler (e.g., GCC, Clang, or MSVC)
- Windows (for the provided executable) or any platform with a C++ compiler

### To Compile the Source Code:
1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/cpp-vector-implementation.git
    ```
2. Navigate to the project directory:
    ```bash
    cd cpp-vector-implementation
    ```
3. Compile the `vector.cpp` file:
    ```bash
    g++ vector.cpp -o vector
    ```

4. Run the executable (Linux/macOS):
    ```bash
    ./vector
    ```

5. Or, on Windows:
    ```bash
    vector.exe
    ```

## Usage

The program tests the custom vector class by performing various operations such as adding, removing, and accessing elements. The results are printed to the console, demonstrating the functionality and correctness of the implementation.

## Comments and Documentation

- Every function is thoroughly documented with comments explaining the logic, memory management decisions, and how each method contributes to the overall functionality of the vector.
- This serves as a learning tool for anyone interested in C++ dynamic memory and custom container implementation.

## Key Learning Areas

- **Dynamic Memory Management**: Learned how to properly allocate, resize, and deallocate memory using pointers in C++.
- **Operator Overloading**: Implemented custom operators (e.g., `[]`) to improve the usability of the vector class.
- **Functionality**: Implemented core functions that allow the vector to handle variable-size arrays efficiently, mimicking the behavior of `std::vector`.

### License

This project is licensed under the ISC License:

Copyright (c) 2024, Justus Jones

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

---

Made by [Justus Jones](https://github.com/Jorstors)

