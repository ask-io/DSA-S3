/*

 * AUTHOR  : Abhijit Smiju Kunnel
 * CLASS   : CSE B
 * ROLL NO : 2
 * REG NO  : 25CS005
 
 */
#include <stdio.h>

struct Term {
    int row;
    int col;
    int val;
};

struct Term A[20], B[20], Sum[40], Trans[20];

int createSparse(struct Term A[], int r, int c) {
    int i, j, k = 1, value;
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &value);
            
            if(value != 0) {
                A[k].row = i;
                A[k].col = j;
                A[k].val = value;
                k++;
            }
        }
    }
    A[0].row = r;
    A[0].col = c;
    A[0].val = k - 1;

    return k;
}

void displaySparse(struct Term p[], int k) {
    if (k <= 0) {
        printf("Matrix not initialized!\n");
        return;
    }
    printf("ROW \tCOL \t Value\n");
    for(int i = 0; i < k; i++) {
        printf("%d \t%d \t%d\n", p[i].row, p[i].col, p[i].val);
    }    
}

int addSparse(struct Term a[], struct Term b[], struct Term c[], int k1, int k2) {
    int i = 1, j = 1, k3 = 1;

    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        printf("Matrices dimensions do not match for addition!\n");
        return 0;
    }

    while(i < k1 && j < k2) {
        if(a[i].row < b[j].row) {
            c[k3++] = a[i++];
        }
        else if (a[i].row > b[j].row) {
            c[k3++] = b[j++];
        }
        else if (a[i].col < b[j].col) {
            c[k3++] = a[i++];
        }
        else if (a[i].col > b[j].col) {
            c[k3++] = b[j++];
        }
        else {
            if (a[i].val + b[j].val != 0) {
                c[k3].row = a[i].row;
                c[k3].col = a[i].col;
                c[k3].val = a[i].val + b[j].val;                
                k3++;
            }
            i++;
            j++;
        }
    }

    while(i < k1) {
        c[k3++] = a[i++];
    }
    while(j < k2) {
        c[k3++] = b[j++];
    }

    c[0].row = a[0].row;
    c[0].col = a[0].col;
    c[0].val = k3 - 1;

    return k3;
}

int transposeSparse(struct Term a[], struct Term trans[], int k) {
    if (k <= 0) return 0;

    trans[0].row = a[0].col;
    trans[0].col = a[0].row;
    trans[0].val = a[0].val;

    int k_trans = 1;

    for (int col = 0; col < a[0].col; col++) {
        for (int i = 1; i < k; i++) {
            if (a[i].col == col) {
                trans[k_trans].row = a[i].col;
                trans[k_trans].col = a[i].row;
                trans[k_trans].val = a[i].val;
                k_trans++;
            }
        }
    }

    return k_trans;
}

int main() {
    int option, k1 = 0, k2 = 0, k3 = 0, kt = 0, f = 1, r, c;
    
    do {
        printf("\n--- Choose the following options ---\n");
        printf("1) Create Sparse\n2) Display Sparse\n3) Add Sparse\n4) Transpose Matrix A\n5) Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Enter no. of rows and columns: ");
            scanf("%d %d", &r, &c);
            printf("\n--Creating Sparse Matrix A--\n");
            k1 = createSparse(A, r, c);
            
            printf("\n--Creating Sparse Matrix B--\n");
            k2 = createSparse(B, r, c);
            break;

        case 2:
            printf("\n--Displaying Sparse Matrix A--\n");
            displaySparse(A, k1);
            printf("\n--Displaying Sparse Matrix B--\n");
            displaySparse(B, k2);
            break;

        case 3:
            printf("\n--Matrix Addition--\n");
            k3 = addSparse(A, B, Sum, k1, k2);
            if (k3 > 0) {
                printf("\n--Displaying Sparse Matrix After Addition--\n");
                displaySparse(Sum, k3);
            }
            break;

        case 4:
            printf("\n--Transposing Matrix A--\n");
            kt = transposeSparse(A, Trans, k1);
            if (kt > 0) {
                printf("\n--Displaying Transposed Matrix A--\n");
                displaySparse(Trans, kt);
            } else {
                printf("Create Matrix A first!\n");
            }
            break;

        case 5:
            printf("Exiting Program...\n");
            f = 0;
            break;

        default:
            printf("Invalid Input!\n");
            break;
        }
    } while(f == 1);

    return 0;
}