/*

 * AUTHOR  : Abhijit Smiju Kunnel
 * CLASS   : CSE B
 * ROLL NO : 2
 * REG NO  : 25CS005
 
 */
#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node *next;
 };

struct node *poly1 = NULL, *poly2 = NULL, *sum = NULL, *temp, *newnode;

void insertPoly1() {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Coefficient: ");
    scanf("%d", &newnode->coeff);
    printf("Enter Exponent: ");
    scanf("%d", &newnode->exp);
    newnode->next = NULL;

    if (poly1 == NULL) {
        poly1 = newnode;
    } else {
        temp = poly1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Term Inserted into Polynomial 1 Successfully.\n");
}

void insertPoly2() {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Coefficient: ");
    scanf("%d", &newnode->coeff);
    printf("Enter Exponent: ");
    scanf("%d", &newnode->exp);
    newnode->next = NULL;

    if (poly2 == NULL) {
        poly2 = newnode;
    } else {
        temp = poly2;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Term Inserted into Polynomial 2 Successfully.\n");
}

void addPolynomials() {
    struct node *p1 = poly1;
    struct node *p2 = poly2;
    struct node *last = NULL;

    sum = NULL;

    while (p1 != NULL && p2 != NULL) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;

        if (p1->exp > p2->exp) {
            newnode->coeff = p1->coeff;
            newnode->exp = p1->exp;
            p1 = p1->next;
        } else if (p2->exp > p1->exp) {
            newnode->coeff = p2->coeff;
            newnode->exp = p2->exp;
            p2 = p2->next;
        } else {
            newnode->coeff = p1->coeff + p2->coeff;
            newnode->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }

        if (sum == NULL) {
            sum = newnode;
            last = sum;
        } else {
            last->next = newnode;
            last = newnode;
        }
    }

    while (p1 != NULL) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->coeff = p1->coeff;
        newnode->exp = p1->exp;
        newnode->next = NULL;
        if (sum == NULL) {
            sum = newnode;
            last = sum;
        } else {
            last->next = newnode;
            last = newnode;
        }
        p1 = p1->next;
    }

    while (p2 != NULL) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->coeff = p2->coeff;
        newnode->exp = p2->exp;
        newnode->next = NULL;
        if (sum == NULL) {
            sum = newnode;
            last = sum;
        } else {
            last->next = newnode;
            last = newnode;
        }
        p2 = p2->next;
    }
}

void displayList(struct node *head) {
    temp = head;
    if (head == NULL) {
        printf("Empty!");
    } else {
        while (temp != NULL) {
            printf("%dx^%d", temp->coeff, temp->exp);
            if (temp->next != NULL) {
                printf(" + ");
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int option, f = 1;

    do {
        printf("\n--- Choose the following options ---\n");
        printf("1) Insert Term in Polynomial 1\n");
        printf("2) Insert Term in Polynomial 2\n");
        printf("3) Display Polynomial 1\n");
        printf("4) Display Polynomial 2\n");
        printf("5) Add Polynomials and Display Result\n");
        printf("6) Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                insertPoly1();
                break;
            case 2:
                insertPoly2();
                break;
            case 3:
                printf("Polynomial 1: ");
                displayList(poly1);
                break;
            case 4:
                printf("Polynomial 2: ");
                displayList(poly2);
                break;
            case 5:
                addPolynomials();
                printf("Sum: ");
                displayList(sum);
                break;
            case 6:
                printf("Exiting Program\n");
                f = 0;
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    } while (f == 1);

    return 0;
}