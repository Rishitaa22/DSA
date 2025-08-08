#include <stdio.h>

int main() {
    int row, col, row2, col2;

    printf("Enter the row and column of 1st matrix:\n");
    scanf("%d %d", &row, &col);

    printf("Enter the row and column of 2nd matrix:\n");
    scanf("%d %d", &row2, &col2);

    if (row != row2 || col != col2) {
        printf("Matrix dimensions must match for addition.\n");
        return 1;
    }

    int arr[row][col], arr2[row2][col2];

    printf("Enter the first sparse matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the second sparse matrix:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("The 1st sparse matrix is:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("The 2nd sparse matrix is:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    int arr3[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr3[i][j] = arr[i][j] + arr2[i][j];
        }
    }

    printf("The resultant sparse matrix is:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }

    // Transpose of arr3
    int transpose[col][row];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transpose[j][i] = arr3[i][j];
        }
    }

    printf("The transpose matrix is:\n");
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Compact matrix representation of transpose
    printf("The compact matrix of transpose is:\n");

    // Count non-zero elements
    int count = 0;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (transpose[i][j] != 0) {
                count++;
            }
        }
    }

    // Print header of compact matrix
    printf("%d %d %d\n", col, row, count);  // rows, cols, non-zero count

    // Print each non-zero element as (row, col, value)
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (transpose[i][j] != 0) {
                printf("%d %d %d\n", i, j, transpose[i][j]);
            }
        }
    }

    return 0;
}
