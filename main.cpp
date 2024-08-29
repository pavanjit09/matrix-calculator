#include <iostream>
using namespace std;

const int MAX = 10;  // Maximum size of the matrix

// Function prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2;
    int choice;

    while (true) {
        // Display menu
        cout << "\nMatrix Calculator\n";
        cout << "1. Add Matrices\n";
        cout << "2. Subtract Matrices\n";
        cout << "3. Multiply Matrices\n";
        cout << "4. Transpose Matrix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting...\n";
            break;  // Exit the loop to end the program
        }

        // Get matrix dimensions and elements based on the operation
        if (choice == 1 || choice == 2) {
            // For addition and subtraction, both matrices must have the same dimensions
            cout << "Enter the number of rows and columns for the matrices: ";
            cin >> rows1 >> cols1;
            rows2 = rows1;
            cols2 = cols1;

            cout << "Enter elements of the first matrix:\n";
            inputMatrix(matrix1, rows1, cols1);
            cout << "Enter elements of the second matrix:\n";
            inputMatrix(matrix2, rows2, cols2);

            if (choice == 1) {
                addMatrices(matrix1, matrix2, result, rows1, cols1);
                cout << "Result of addition:\n";
            }
            else {
                subtractMatrices(matrix1, matrix2, result, rows1, cols1);
                cout << "Result of subtraction:\n";
            }
            displayMatrix(result, rows1, cols1);

        }
        else if (choice == 3) {
            // For multiplication, the number of columns in the first matrix must equal the number of rows in the second
            cout << "Enter the number of rows and columns for the first matrix: ";
            cin >> rows1 >> cols1;
            cout << "Enter the number of rows and columns for the second matrix: ";
            cin >> rows2 >> cols2;

            if (cols1 != rows2) {
                cout << "Error: The number of columns of the first matrix must equal the number of rows of the second matrix for multiplication.\n";
                continue;  // Restart the loop
            }

            cout << "Enter elements of the first matrix:\n";
            inputMatrix(matrix1, rows1, cols1);
            cout << "Enter elements of the second matrix:\n";
            inputMatrix(matrix2, rows2, cols2);

            multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
            cout << "Result of multiplication:\n";
            displayMatrix(result, rows1, cols2);

        }
        else if (choice == 4) {
            // For transposition, just need one matrix
            cout << "Enter the number of rows and columns for the matrix: ";
            cin >> rows1 >> cols1;

            cout << "Enter elements of the matrix:\n";
            inputMatrix(matrix1, rows1, cols1);

            transposeMatrix(matrix1, result, rows1, cols1);
            cout << "Transpose of the matrix:\n";
            displayMatrix(result, cols1, rows1);  // Note: rows and cols are swapped in the result

        }
        else {
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }
    return 0;
}

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Function to add two matrices
void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2) {
    // Initialize the result matrix with zeros
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];  // Swap rows and columns
        }
    }
}
