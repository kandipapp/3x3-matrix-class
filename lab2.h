#ifndef LAB2_H   // HEADER GURADS
#define LAB2_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

/**
 * Matrix Class
 * A class for representing and manipulating 3x3 matrices
 * Supports basic operations, utility functions, and advanced mathematical operations
 */

class Matrix {
private:
    double data[3][3];  // 3x3 array to store matrix elements

public:

    // Constructor
    Matrix();

    // Basic Functions
    void print();                                   // Display matrix neatly
    void set(double a, double b, double c, double d, double e, double f, double g, double h, double i);   // Set all 9 elements
    void set(int m, int n, double x);               // Set specific element at (m,n)
    double get(int m, int n);                       // Get element at (m,n)


    // Utility Functions
    void transpose();                               // Transpose the matrix
    void eye();                                     // Set to identity matrix
    void zero();                                    // Set all elements to zero
    void save(string filename);                     // Save matrix to file
    void load(string filename);                     // Load matrix from file


    // Mathematical Operations
    void add(Matrix B);                             // Add matrix B to current matrix
    void sub(Matrix B);                             // Subtract matrix B from current
    double rcMult(Matrix B, int row, int col);      // Row-column multiplication
    void lMult(Matrix B);                           // Left multiply: B * this
    void rMult(Matrix B);                           // Right multiply: this * B
    void sMult(double s);                           // Scalar multiplication
    double det();                                   // Calculate determinant
    void inv();                                     // Invert the matrix


private:
    // Helper function for calculating 2x2 determinant (used in inverse calculation)
    double det2x2(double a, double b, double c, double d) {
        return ((a * d) - (b * c));
    }
};

#endif // LAB2_H
