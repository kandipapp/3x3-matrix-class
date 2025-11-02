#include "Matrix.h"

/**
 * Constructor
 * Initializes matrix with all zeros
 */
Matrix::Matrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = 0.0;
        }
    }
}

// ============================== Basic Functions Definitions ==============================
/**
 * Print matrix in a neat format
 * Displays all elements with proper alignment
 */
void Matrix::print(){
    cout << "[" << setw(4) << data[0][0] << " " << setw(4) << data[0][1] << " " << setw(4) << data[0][2] << "]" << "\n";
    cout << "[" << setw(4) << data[1][0] << " " << setw(4) << data[1][1] << " " << setw(4) << data[1][2] << "]" << "\n";
    cout << "[" << setw(4) << data[2][0] << " " << setw(4) << data[2][1] << " " << setw(4) << data[2][2] << "]" << "\n";
}


/**
 * Set all 9 elements of the matrix at once
 * Parameters ordered as: row 0, row 1, row 2
 */
void Matrix::set(double a, double b, double c,    // Set all 9 elements
                 double d, double e, double f,
                 double g, double h, double i){
    data[0][0] = a;    data[0][1] = b;    data[0][2] = c;
    data[1][0] = d;    data[1][1] = e;    data[1][2] = f;
    data[2][0] = g;    data[2][1] = h;    data[2][2] = i;
}


/**
 * Set a specific element at position (m, n)
 * @param m: row index (0-2)
 * @param n: column index (0-2)
 * @param x: value to set
 */
void Matrix::set(int m, int n, double x) {
    if (m >= 0 && m < 3 && n >= 0 && n < 3) {
        data[m][n] = x;
    } else {
        cout << "Error: Index out of bounds!" << endl;
    }
}


/**
 * Get element at position (m, n)
 * @param m: row index (0-2)
 * @param n: column index (0-2)
 * @return: value at position (m, n)
 */
double Matrix::get(int m, int n) {
    if (m >= 0 && m < 3 && n >= 0 && n < 3) {
        return data[m][n];
    } else {
        cout << "Error: Index out of bounds!" << endl;
        return 0.0;
    }
}

//===========================================================================================


// ============================== Utility Functions Definitions =============================
/**
 * Transpose the matrix (swap rows and columns)
 * Element (i,j) becomes element (j,i)
 */
void Matrix::transpose(){
    Matrix temp;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp.data[i][j] = data[j][i];
        }
    }
    // Copy transposed values back
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = temp.data[i][j];
        }
    }
}

/**
 * Set matrix to identity matrix
 * Diagonal elements = 1, all others = 0
 */
void Matrix::eye() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}

/**
 * Set all matrix elements to zero
 */
void Matrix::zero() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = 0.0;
        }
    }
}

/**
 * Save matrix to a text file
 * @param filename: name of file to save (e.g., "matrix12345678.txt")
 */
void Matrix::save(string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << fixed << setprecision(6);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                file << data[i][j];
                if (j < 2) file << " ";
            }
            file << endl;
        }
        file.close();
        cout << "Matrix saved to " << filename << endl;
    } else {
        cout << "Error: Unable to open file for writing!" << endl;
    }
}

/**
 * Load matrix from a text file
 * @param filename: name of file to load
 */
void Matrix::load(string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                file >> data[i][j];
            }
        }
        file.close();
        cout << "Matrix loaded from " << filename << endl;
    } else {
        cout << "Error: Unable to open file for reading!" << endl;
    }
}

//===========================================================================================


// ============================== Mathematical Operations =============================
/**
 * Add matrix B to current matrix
 * Element-wise addition: this = this + B
 */
void Matrix::add(Matrix B) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] += B.data[i][j];
        }
    }
}

/**
 * Subtract matrix B from current matrix
 * Element-wise subtraction: this = this - B
 */
void Matrix::sub(Matrix B) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] -= B.data[i][j];
        }
    }
}

/**
 * Multiply a row of current matrix with a column of matrix B
 * Used as helper for matrix multiplication
 * @param B: matrix to multiply with
 * @param row: row index of current matrix
 * @param col: column index of matrix B
 * @return: dot product result
 */
double Matrix::rcMult(Matrix B, int row, int col) {
    double result = 0.0;
    for (int k = 0; k < 3; k++) {
        result += data[row][k] * B.data[k][col];
    }
    return result;
}

/**
 * Left multiply: this = B * this
 * Multiplies matrix B on the left side
 */
void Matrix::lMult(Matrix B) {
    Matrix result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.data[i][j] = 0.0;
            for (int k = 0; k < 3; k++) {
                result.data[i][j] += B.data[i][k] * data[k][j];
            }
        }
    }
    // Copy result back to current matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = result.data[i][j];
        }
    }
}

/**
 * Right multiply: this = this * B
 * Multiplies matrix B on the right side
 */
void Matrix::rMult(Matrix B) {
    Matrix result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.data[i][j] = rcMult(B, i, j);
        }
    }
    // Copy result back to current matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = result.data[i][j];
        }
    }
}

/**
 * Scalar multiplication
 * Multiply every element by scalar s
 */
void Matrix::sMult(double s) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] *= s;
        }
    }
}

/**
 * Calculate determinant using the rule of Sarrus
 * det = (a00*a11*a22 + a01*a12*a20 + a02*a10*a21)
 *     - (a20*a11*a02 + a21*a12*a00 + a22*a10*a01)
 * @return: determinant value
 */
double Matrix::det() {
    double a00 = data[0][0], a01 = data[0][1], a02 = data[0][2];
    double a10 = data[1][0], a11 = data[1][1], a12 = data[1][2];
    double a20 = data[2][0], a21 = data[2][1], a22 = data[2][2];

    double positive = (a00 * a11 * a22) + (a01 * a12 * a20) + (a02 * a10 * a21);
    double negative = (a20 * a11 * a02) + (a21 * a12 * a00) + (a22 * a10 * a01);

    return (positive - negative);
}

/**
 * Invert the matrix using cofactor method
 * Steps: 1) Calculate determinant
 *        2) Calculate cofactor matrix
 *        3) Transpose cofactor matrix (adjugate)
 *        4) Divide by determinant
 */
void Matrix::inv() {
    double determinant = det();

    // Check if matrix is invertible
    if (fabs(determinant) < 1e-10) { //floating-point absolute value: check the determinant is lesser than 0.0000000001 (almost zero)
        cout << "Error: Matrix is singular (determinant = 0), cannot invert!" << endl;
        return;
    }

    // Calculate cofactor matrix
    Matrix cofactor;

    // Cofactor elements using 2x2 determinants
    cofactor.data[0][0] = det2x2(data[1][1], data[1][2], data[2][1], data[2][2]);
    cofactor.data[0][1] = -det2x2(data[1][0], data[1][2], data[2][0], data[2][2]);
    cofactor.data[0][2] = det2x2(data[1][0], data[1][1], data[2][0], data[2][1]);

    cofactor.data[1][0] = -det2x2(data[0][1], data[0][2], data[2][1], data[2][2]);
    cofactor.data[1][1] = det2x2(data[0][0], data[0][2], data[2][0], data[2][2]);
    cofactor.data[1][2] = -det2x2(data[0][0], data[0][1], data[2][0], data[2][1]);

    cofactor.data[2][0] = det2x2(data[0][1], data[0][2], data[1][1], data[1][2]);
    cofactor.data[2][1] = -det2x2(data[0][0], data[0][2], data[1][0], data[1][2]);
    cofactor.data[2][2] = det2x2(data[0][0], data[0][1], data[1][0], data[1][1]);

    // Transpose cofactor matrix to get adjugate
    cofactor.transpose();

    // Divide by determinant and store in current matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = cofactor.data[i][j] / determinant;
        }
    }
}

//===========================================================================================
