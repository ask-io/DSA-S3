#include <stdio.h>
#define MAX 100

typedef struct {
    int row, col, val;
} Term;

void createSparse(Term t[], int rows, int cols) {
    int mat[20][20];
    int k = 1;

    printf("Enter %d x %d matrix elements (row by row):\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                t[k].row = i;
                t[k].col = j;
                t[k].val = mat[i][j];
                k++;
            }
        }
    }
    t[0].row = rows;
    t[0].col = cols;
    t[0].val = k - 1;
}

void printSparse(Term a[], int size) {
    printf("Row Col Value\n");
    for (int i = 0; i < size; i++)
        printf("%3d %3d %5d\n", a[i].row, a[i].col, a[i].val);
}

int addSparse(Term a[], int m, Term b[], int n, Term result[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        printf("Matrices dimensions do not match!\n");
        return -1;
    }
    int i = 1, j = 1, k = 1;
    while (i < m && j < n) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result[k++] = a[i++];
        }
        else if (a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)) {
            result[k++] = b[j++];
        }
        else {
            int sum = a[i].val + b[j].val;
            if (sum != 0) {
                result[k].row = a[i].row;
                result[k].col = a[i].col;
                result[k].val = sum;
                k++;
            }
            i++; j++;
        }
    }
    while (i < m) result[k++] = a[i++];
    while (j < n) result[k++] = b[j++];

    result[0].row = a[0].row;
    result[0].col = a[0].col;
    result[0].val = k - 1;
    return k;
}

void transposeSparse(Term a[], Term t[]) {
    int rows = a[0].row, cols = a[0].col, terms = a[0].val;
    t[0].row = cols;
    t[0].col = rows;
    t[0].val = terms;
    if (terms <= 0) return;

    int colCount[MAX] = {0}, colStart[MAX] = {0};
    for (int i = 1; i <= terms; i++)
        colCount[a[i].col]++;

    colStart[0] = 1;
    for (int i = 1; i < cols; i++)
        colStart[i] = colStart[i - 1] + colCount[i - 1];

    for (int i = 1; i <= terms; i++) {
        int col = a[i].col;
        int pos = colStart[col];
        t[pos].row = a[i].col;
        t[pos].col = a[i].row;
        t[pos].val = a[i].val;
        colStart[col]++;
    }
}

int main() {
    Term A[MAX], B[MAX], sum[MAX], trans[MAX];
    int rows, cols;

    printf("Enter number of rows and columns for both matrices: ");
    scanf("%d %d", &rows, &cols);

    printf("\n-- Matrix A --\n");
    createSparse(A, rows, cols);

    printf("\n-- Matrix B --\n");
    createSparse(B, rows, cols);

    printf("\nSparse form of A:\n");
    printSparse(A, A[0].val + 1);

    printf("\nSparse form of B:\n");
    printSparse(B, B[0].val + 1);

    int size = addSparse(A, A[0].val + 1, B, B[0].val + 1, sum);
    printf("\nSum Matrix (triplet form):\n");
    printSparse(sum, size);

    transposeSparse(sum, trans);
    printf("\nTranspose of Sum (triplet form):\n");
    printSparse(trans, trans[0].val + 1);

    return 0;
}