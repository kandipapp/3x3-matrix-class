#include "lab2.h"

using namespace std;

int main()
{
    cout << "============================================" << endl;
    cout << "    EEEE2065 Lab 2 - Matrix Class Demo     " << endl;
    cout << "    Student ID: 20615981         " << endl;
    cout << "============================================\n" << endl;

    // Create matrix objects for testing
    Matrix A, B, C;

    // ========================================
    // TEST 1: SET (all 9 elements) and PRINT
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 1: set(9 elements) and print()" << endl;
    cout << "========================================" << endl;
    A.print();
    A.set(1, 2, 3,
          4, 5, 6,
          7, 8, 9);
    cout << "Matrix A (using set with 9 parameters):" << endl;
    A.print();


    // ========================================
    // TEST 2: SET (single element) Function
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 2: set(m, n, value)" << endl;
    cout << "========================================" << endl;
    cout << "Setting element at position (1,1) to 99" << endl;
    A.set(1, 1, 99);
    cout << "Matrix A after changing (1,1):" << endl;
    A.print();


    // ========================================
    // TEST 3: GET Function
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 3: get(m, n)" << endl;
    cout << "========================================" << endl;
    double value = A.get(1, 1);
    cout << "Element at position (1,1): " << value << endl;
    value = A.get(0, 2);
    cout << "Element at position (0,2): " << value << "\n" << endl;

    // Reset A for other tests
    A.set(1, 2, 3,
          4, 5, 6,
          7, 8, 9);

    // ========================================
    // TEST 4: EYE (Identity Matrix)
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 4: eye()" << endl;
    cout << "========================================" << endl;
    B.eye();
    cout << "Identity Matrix B:" << endl;
    B.print();

    // ========================================
    // TEST 5: ZERO Function
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 5: zero()" << endl;
    cout << "========================================" << endl;
    C.set(10, 20, 30,
          40, 50, 60,
          70, 80, 90);
    cout << "Matrix C before zero():" << endl;
    C.print();
    C.zero();
    cout << "Matrix C after zero():" << endl;
    C.print();

    // ========================================
    // TEST 6: TRANSPOSE
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 6: transpose()" << endl;
    cout << "========================================" << endl;
    A.set(1, 2, 3,
          4, 5, 6,
          7, 8, 9);
    cout << "Matrix A before transpose:" << endl;
    A.print();
    A.transpose();
    cout << "Matrix A after transpose:" << endl;
    A.print();

    // Reset A
    A.set(1, 2, 3,
          4, 5, 6,
          7, 8, 9);

    // ========================================
    // TEST 7: ADD Function
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 7: add(Matrix B)" << endl;
    cout << "========================================" << endl;
    A.set(1, 2, 3,
          4, 5, 6,
          7, 8, 9);
    B.set(9, 8, 7,
          6, 5, 4,
          3, 2, 1);
    cout << "Matrix A:" << endl;
    A.print();
    cout << "Matrix B:" << endl;
    B.print();
    A.add(B);
    cout << "Result: A + B =" << endl;
    A.print();

    // ========================================
    // TEST 8: SUB Function
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 8: sub(Matrix B)" << endl;
    cout << "========================================" << endl;
    A.set(10, 20, 30,
          40, 50, 60,
          70, 80, 90);
    B.set(1, 2, 3,
          4, 5, 6,
          7, 8, 9);
    cout << "Matrix A:" << endl;
    A.print();
    cout << "Matrix B:" << endl;
    B.print();
    A.sub(B);
    cout << "Result: A - B =" << endl;
    A.print();

    // ========================================
    // TEST 9: sMult (Scalar Multiplication)
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 9: sMult(scalar)" << endl;
    cout << "========================================" << endl;
    A.set(1, 2, 3,
          4, 5, 6,
          7, 8, 9);
    cout << "Matrix A:" << endl;
    A.print();
    cout << "Multiplying by scalar 3:" << endl;
    A.sMult(3);
    cout << "Result: A * 3 =" << endl;
    A.print();

    // ========================================
    // TEST 10: rcMult (Row-Column Multiplication)
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 10: rcMult(Matrix B, row, col)" << endl;
    cout << "========================================" << endl;
    A.set(1, 2, 3,
          4, 5, 6,
          7, 8, 9);
    B.set(9, 8, 7,
          6, 5, 4,
          3, 2, 1);
    cout << "Matrix A:" << endl;
    A.print();
    cout << "Matrix B:" << endl;
    B.print();
    double rcResult = A.rcMult(B, 0, 0);
    cout << "Row 0 of A * Column 0 of B = " << rcResult << "\n" << endl;

    // ========================================
    // TEST 11: rMult (Right Multiplication)
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 11: rMult(Matrix B)" << endl;
    cout << "========================================" << endl;
    A.set(1, 2, 3,
          4, 5, 6,
          7, 8, 9);
    B.set(9, 8, 7,
          6, 5, 4,
          3, 2, 1);
    cout << "Matrix A:" << endl;
    A.print();
    cout << "Matrix B:" << endl;
    B.print();
    A.rMult(B);
    cout << "Result: A * B (right multiply) =" << endl;
    A.print();


    // ========================================
    // TEST 12: lMult (Left Multiplication)
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 12: lMult(Matrix B)" << endl;
    cout << "========================================" << endl;
    A.set(1, 2, 3,
          4, 5, 6,
          7, 8, 9);
    B.set(9, 8, 7,
          6, 5, 4,
          3, 2, 1);
    cout << "Matrix A:" << endl;
    A.print();
    cout << "Matrix B:" << endl;
    B.print();
    A.lMult(B);
    cout << "Result: B * A (left multiply) =" << endl;
    A.print();


    // ========================================
    // TEST 13: SAVE Function
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 13: save(filename)" << endl;
    cout << "========================================" << endl;
    A.set(1.5, 2.5, 3.5,
          4.5, 5.5, 6.5,
          7.5, 8.5, 9.5);
    cout << "Matrix A to be saved:" << endl;
    A.print();
    A.save("matrix20615981.txt");
    cout << "Matrix saved successfully!\n" << endl;


    // ========================================
    // TEST 14: LOAD Function
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 14: load(filename)" << endl;
    cout << "========================================" << endl;
    Matrix D;
    cout << "Loading matrix from file..." << endl;
    D.load("matrix20615981.txt");
    cout << "Loaded Matrix D:" << endl;
    D.print();

    // ========================================
    // TEST 15: DET (Determinant)
    // ========================================
    cout << endl<< "========================================" << endl;
    cout << "TEST 15: det()" << endl;
    cout << "========================================" << endl;
    A.set(1, 2, 3,
          0, 1, 4,
          5, 6, 0);
    cout << "Matrix A:" << endl;
    A.print();
    double determinant = A.det();
    cout << "Determinant of A = " << determinant << "\n" << endl;

    // Another determinant example
    B.set(6, 1, 1,
          4, -2, 5,
          2, 8, 7);
    cout << "Matrix B:" << endl;
    B.print();
    determinant = B.det();
    cout << "Determinant of B = " << determinant << "\n" << endl;


    // ========================================
    // TEST 16: INV (Inverse Matrix)
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 16: inv()" << endl;
    cout << "========================================" << endl;
    A.set(1, 2, 3,
          0, 1, 4,
          5, 6, 0);
    cout << "Original Matrix A:" << endl;
    A.print();
    cout << "Determinant: " << A.det() << endl << endl;

    // Create a copy to verify
    Matrix A_copy;
    A_copy.set(1, 2, 3,
               0, 1, 4,
               5, 6, 0);

    A.inv();
    cout << "Inverse of A:" << endl;
    A.print();

    // Verify: A * A_inverse should give identity matrix
    cout << "Verification: A * A_inverse (should be identity):" << endl;
    A_copy.rMult(A);
    A_copy.print();


    // ========================================
    // TEST 17: Singular Matrix (No Inverse)
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "TEST 17: inv() on Singular Matrix" << endl;
    cout << "========================================" << endl;
    Matrix singular;
    singular.set(1, 2, 3,
                 2, 4, 6,
                 3, 6, 9);
    cout << "Singular Matrix (determinant = 0):" << endl;
    singular.print();
    cout << "Determinant: " << singular.det() << endl;
    cout << "Attempting to invert..." << endl;
    singular.inv();
    cout << endl;


    // ========================================
    // COMPREHENSIVE EXAMPLE
    // ========================================
    cout << endl << "========================================" << endl;
    cout << "COMPREHENSIVE EXAMPLE" << endl;
    cout << "========================================" << endl;

    Matrix M1, M2, M3;

    // Create two matrices
    M1.set(2, 0, 1,
           1, 3, 0,
           0, 1, 2);
    M2.set(1, 0, 0,
           0, 1, 0,
           0, 0, 1);

    cout << "Matrix M1:" << endl;
    M1.print();
    cout << "Matrix M2 (Identity):" << endl;
    M2.print();

    // Perform operations
    M3 = M1;
    M3.set(M1.get(0,0), M1.get(0,1), M1.get(0,2),
           M1.get(1,0), M1.get(1,1), M1.get(1,2),
           M1.get(2,0), M1.get(2,1), M1.get(2,2));

    M3.add(M2);
    cout << "M1 + M2:" << endl;
    M3.print();

    M3.set(M1.get(0,0), M1.get(0,1), M1.get(0,2),
           M1.get(1,0), M1.get(1,1), M1.get(1,2),
           M1.get(2,0), M1.get(2,1), M1.get(2,2));
    M3.sMult(2);
    cout << "M1 * 2:" << endl;
    M3.print();

    cout << "Determinant of M1: " << M1.det() << "\n" << endl;

    cout << "============================================" << endl;
    cout << "    ALL TESTS COMPLETED SUCCESSFULLY!      " << endl;
    cout << "============================================" << endl;

    return 0;






}




