//WAP that reads two matrices A (m x n) and B (p x q) and computes the (a) sum (b) product (c) determinant of A and B. Read matrix A and matrix B in row major order respectively. Print both the input matrices and resultant matrix with suitable headings and output should be in matrix format only. Program must check the compatibility of orders of the matrices for multiplication. Report appropriate message in case of incompatibility.
#include <stdio.h>
#define MAX 10
void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int m, int n, int p, int q) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
int determinant(int matrix[MAX][MAX], int n) {
    int det = 0;
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    }
    int temp[MAX][MAX];
    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x)
                    continue;
                temp[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(temp, n - 1);
    }
    return det;
}
int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int m, n, p, q;
    printf("Enter rows and columns for matrix A: ");
    scanf("%d %d", &m, &n);
    printf("Enter elements of matrix A:\n");
    readMatrix(A, m, n);
    printf("Enter rows and columns for matrix B: ");
    scanf("%d %d", &p, &q);
    printf("Enter elements of matrix B:\n");
    readMatrix(B, p, q);
    printf("Matrix A:\n");
    printMatrix(A, m, n);
    printf("Matrix B:\n");
    printMatrix(B, p, q);
    if (m == p && n == q) {
        addMatrices(A, B, result, m, n);
        printf("Sum of A and B:\n");
        printMatrix(result, m, n);
    } else {
        printf("Addition not possible due to incompatible dimensions.\n");
    }
    if (n == p) {
        multiplyMatrices(A, B, result, m, n, p, q);
        printf("Product of A and B:\n");
        printMatrix(result, m, q);
    } else {
        printf("Multiplication not possible due to incompatible dimensions.\n");
    }
    if (m == n) {
        int detA = determinant(A, m);
        printf("Determinant of matrix A: %d\n", detA);
    } else {
        printf("Determinant of matrix A not possible as it is not square.\n");
    }
    if (p == q) {
        int detB = determinant(B, p);
        printf("Determinant of matrix B: %d\n", detB);
    } else {
        printf("Determinant of matrix B not possible as it is not square.\n");
    }
    return 0;
}