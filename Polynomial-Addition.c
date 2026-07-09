#include <stdio.h>

struct Term
{
    int coef;
    int expo;
};

struct Term x1[20], x2[20], x3[40];


int read(struct Term p[]) {             //Read the polynomial
    int i, terms;
    printf("Enter number of terms: ");
    scanf("%d", &terms);
    for(i=0;i<terms; i++){
        printf("Enter term %d --> Coeffiecent:", i+1);
        scanf("%d", &p[i].coef);
        printf("Enter term %d --> Exponent:", i+1);
        scanf("%d", &p[i].expo);
    }
    return terms;
}

void display(struct Term p[], int terms){
    int i;
    if(terms == 0)
        printf("No polynomial created");
    else{
        for(i=0; i<terms; i++){
            printf("%dx^%d", p[i].coef, p[i].expo);
            if(i<terms-1)
                printf(" + ");
        }
    }
}

int add(struct Term p1[], struct Term p2[], struct Term p3[], int terms1, int terms2){
    int i=0, j=0, k=0;
    while(i<terms1 && j<terms2){
        if(p1[i].expo == p2[j].expo){
            p3[k].expo = p1[i].expo;
            p3[k].coef = (p1[i].coef+p2[j].coef);
            i++; j++; k++;
        }
        else if(p1[i].expo > p2[j].expo){
            p3[k].expo = p1[i].expo;
            p3[k].coef = p1[i].coef;
            i++; k++;
        }
        else if(p1[i].expo < p2[j].expo){
            p3[k].expo = p2[j].expo;
            p3[k].coef = p2[j].coef;
            j++; k++;
        }
    }
    while(i<terms1){
        p3[k].coef = p1[i].coef;
        p3[k].expo = p1[i].expo;
        i++; k++;
    }
    while(j<terms2){
        p3[k].coef = p2[j].coef;
        p3[k].expo = p2[j].expo;
        j++; k++;
    }
    return k;
 
}




int main() {
    int t, i, option, t1, t2, t3, f=1;
    
    do{
        printf("\n--- Choose the following options ---\n\n1) Read Polynomial\n2) Display Polynomial\n3) Add Polynomials\n4) Exit\n\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\n------------\n");
            printf("Enter Polynomial 1: ");
            t1 = read(x1);
            printf("\n------------\n");
            printf("Enter Polynomial 2: ");
            t2 = read(x2);
            break;
        case 2:
            printf("\n");
            printf("Displaying Polynomial 1: ");
            display(x1,t1);
            printf("\n");
            printf("Displaying Polynomial 2: ");
            display(x2,t2);
            printf("\n");
            break;
        case 3:
            printf("\n");
            printf("Adding Polynomial 1 & 2: ");
            t3 = add(x1,x2, x3, t1, t2);
            display(x3, t3);
            printf("\n");
            break;
        case 4:
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