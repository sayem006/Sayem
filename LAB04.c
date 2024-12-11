#include <stdio.h>

int main() {
    int m, n, p, q;

    printf("Enter number of rows and columns for matrix A: ");
    scanf("%d %d", &m, &n);
    printf("Enter number of rows and columns for matrix B: ");
    scanf("%d %d", &p, &q);

    // Matrix multiplication is only possible if n == p
    if (n != p) {
        printf("Matrix multiplication is not possible. Number of columns in A must be equal to number of rows in B.\n");
        return 1;
    }
    int A[m][n], B[p][q], C[m][q];
    printf("Enter elements of matrix A (%d x %d): \n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter elements of matrix B (%d x %d): \n", p, q);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
      }
 }
    printf("Result of matrix multiplication (A * B): \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
