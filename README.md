# 3x3-matrix-class
An object-oriented 3x3 Matrix class in C++ for the EEEE2065 coursework at the University of Nottingham Malaysia. 
Developed by 20615981. 
Implements a full suite of mathematical operations, utility functions, and file I/O.

# EEEE2065 Lab 2: C++ 3x3 Matrix Class

![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

A comprehensive, object-oriented 3x3 matrix class written in C++ as part of the "Design and Implementation of Engineering Software" (EEEE2065) coursework for the University of Nottingham.

This project focuses on **modular decomposition** and **object-oriented principles**, separating the class interface, implementation, and testing into distinct files. It provides a robust set of functionalities for matrix manipulation and computation.

## Features Implemented

The `Matrix` class supports a wide range of operations, categorized as follows:

#### ✅ Basic Operations
- **`set()`**: Two overloaded versions for setting all elements or a single element.
- **`get()`**: Retrieve the value of a specific element.
- **`print()`**: Display the matrix in a clean, formatted layout.

#### ✅ Utility Functions
- **`transpose()`**: Swaps the matrix rows with its columns.
- **`eye()`**: Configures the matrix as an identity matrix.
- **`zero()`**: Resets all elements of the matrix to zero.
- **`save()`**: Saves the matrix data to a specified text file.
- **`load()`**: Loads matrix data from a specified text file.

#### ✅ Mathematical Operations
- **`add()` / `sub()`**: Element-wise matrix addition and subtraction.
- **`sMult()`**: Scalar multiplication.
- **`rMult()` / `lMult()`**: Right and left matrix multiplication.
- **`det()`**: Calculates the determinant using Sarrus's rule.
- **`inv()`**: Computes the inverse of the matrix using the cofactor method, with robust handling for singular matrices.

## Project Structure

The code is organized into three separate files, following C++ best practices for modularity and maintainability:

- **`lab2.h`**: The header file containing the `Matrix` class declaration (the public interface).
- **`lab2.cpp`**: The implementation file containing the definitions for all `Matrix` class member functions.
- **`main.cpp`**: The driver file used for demonstrating and systematically testing all functionalities of the `Matrix` class.

## Getting Started

To compile and run this project, you will need a C++ compiler like g++.

### Prerequisites
- A modern C++ compiler (e.g., g++, Clang, MSVC).

### Compilation & Execution (Command Line)

1.  **Clone the repository:**
    ```sh
    git clone https://github.com/kandipapp/3x3-matrix-class.git
    cd 3x3-matrix-class
    ```

2.  **Compile the source files:**
    ```sh
    g++ main.cpp Matrix.cpp -o matrix_demo -std=c++11
    ```

3.  **Run the executable:**
    ```sh
    ./matrix_demo
    ```

### Using an IDE
If you are using an IDE like Code::Blocks, Visual Studio, or CLion, you can simply create a new project, add the three `.cpp` and `.h` files, and click "Build and Run".

## Example Output

The `main.cpp` file runs a comprehensive suite of tests. The output will look like this:

============================================
    EEEE2065 Lab 2 - Matrix Class Demo
    Student ID: 11111111
============================================


========================================
TEST 1: set(9 elements) and print()
========================================
[   0    0    0]
[   0    0    0]
[   0    0    0]
Matrix A (using set with 9 parameters):
[   1    2    3]
[   4    5    6]
[   7    8    9]

... (many more tests) ...


========================================
TEST 17: inv() on Singular Matrix
========================================
Singular Matrix (determinant = 0):
[   1    2    3]
[   2    4    6]
[   3    6    9]
Determinant: 0
Attempting to invert...
Error: Matrix is singular (determinant = 0), cannot invert!




## License

This project is distributed under the MIT License. See the `LICENSE` file for more information.
