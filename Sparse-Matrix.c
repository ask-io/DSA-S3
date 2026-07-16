#include <stdio.h>

struct Term{
    int row;
    int col;
    int val;
};

struct Term A[20], B[20], Sum[40], Trans[40];

int createSparse(struct Term A[], int r, int c){
    int i, j, k=1, l=1, value;
    for(i=0; i<r; i++){
        for(j=0;j<c; j++){
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &value);
            

            if(value != 0){
                A[k].row = i;
                A[k].col = j;
                A[k].val = value;
                k++;
            }
        }
    }
    A[0].row = r;
    A[0].col = c;
    A[0].val = k-1;

    return k;
}

void displaySparse(struct Term p[], int k){
    printf("ROW \tCOL \t Value\n");
    for(int i=0; i<k; i++){
        printf("%d \t%d \t%d\n", p[i].row, p[i].col, p[i].val);
    }    
}

int addSparse(struct Term a[], struct Term b[], struct Term c[], int k1, int k2){
    int i=1,j=1, k3=1;
    while(i<=k1 && j <= k2){
        if(a[i].row < b[j].row){
            c[k3].row = a[i].row;
            c[k3].col = a[i].col;
            c[k3].val = a[i].val;
            i++;
            k3++;
        }
        else if (a[i].row > b[j].row){
            c[k3].row = b[j].row;
            c[k3].col = b[j].col;
            c[k3].val = b[j].val;
            j++;
            k3++;
        }
        else if (a[i].col < b[j].col)
        {
            c[k3].row = a[i].row;
            c[k3].col = a[i].col;
            c[k3].val = a[i].val;
            i++;
            k3++;
        }
        else if (a[i].col > b[j].col)
        {
            c[k3].row = b[j].row;
            c[k3].col = b[j].col;
            c[k3].val = b[j].val;
            j++;
            k3++;
        }
        else{
            if (a[i].val + b[j].val != 0){
                c[k3].row = a[i].row;
                c[k3].col = a[i].col;
                c[k3].val = a[i].val + b[j].val;                
                k3++;
            }
            i++;
            j++;
        }
    }
    while(i <= k1){
            c[k3].row = a[i].row;
            c[k3].col = a[i].col;
            c[k3].val = a[i].val;
            i++;
            k3++;
    }
    while(j<= k2){
            c[k3].row = b[j].row;
            c[k3].col = b[j].col;
            c[k3].val = b[j].val;
            j++;
            k3++;
    }
    c[0].row = a[0].row;
    c[0].col = a[0].col;
    c[0].val = k3-1;

    return k3-1;

}

int main() {
    int t, i, option, k1, k2, k3, t3, f=1, r, c;
    
    do{
        printf("\n--- Choose the following options ---\n\n1) Create Sparse\n2) Display Sparse\n3) Add Sparse\n4) Create Transpose\n5) Exit\n\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter no. of rows and columns: ");
            scanf("%d %d", &r, &c);
            printf("--Creating Sparse Matrix A--\n ");
            k1 = createSparse(A, r, c);
            printf("--Sparse Matrix A Created!--\n ");
            printf("Creating Sparse Matrix B:\n ");
            k2 = createSparse(B, r, c);
            printf("--Sparse Matrix B Created!--\n ");
            break;
        case 2:
            printf("\n");
            printf("--Displaying Sparse Matrix A--\n");
            displaySparse(A, k1);
            printf("\n");
            printf("--Displaying Sparse Matrix B--\n");
            displaySparse(B, k2);
            break;
        case 3:
            printf("--Matrix Addition--\n");
            k3 = addSparse(A, B, Sum, k1, k2);
            printf("--Displaying Sparse Matrix After Addition--\n");
            displaySparse(Sum, k3);
            
            break;
        case 5:
            printf("Exiting Program");
            f=0;
            break;
        default:
            printf("Invalid Input");
            f=0;
            break;
        }
    }while(f=1);
    

}