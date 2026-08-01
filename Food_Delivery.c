/*A food delivery platform maintains the list of active orders. New orders are continuously added, and completed orders are removed.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char order[50];
    struct node *next;
};

struct node *newnode, *f = NULL, *r = NULL, *temp;

void newOrder() {
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    char item[50];
    printf("Enter item name: ");
    scanf(" %[^\n]", item);

    strcpy(newnode->order, item);
    newnode->next = NULL;

    if (f == NULL) {
        f = r = newnode;
    } else {
        r->next = newnode;
        r = newnode;
    }    
    printf("Order \"%s\" has been added to Queue.\n", item);
}

void completedOrder() {
    if (f == NULL) {
        printf("All orders are completed (Queue is empty).\n");
    } else {
        temp = f;
        printf("Order \"%s\" is Completed.\n", temp->order);
        
        if (f == r) {
            f = r = NULL;
        } else {
            f = f->next;
        }
        free(temp);
    }
}

void displayOrders() {
    temp = f;
    if (f == NULL) {
        printf("No Orders in Queue.\n");
    } else {
        printf("\n--- Active Orders Queue ---\n");
        int count = 1;
        while (temp != NULL) {
            printf("%d. %s\n", count++, temp->order);
            temp = temp->next;
        }
    }
}

int main() {
    int option;
    int f = 1; // Renamed variable to avoid shadowing global pointer 'f'

    do {
        printf("\n=== Food Delivery Order System ===\n");
        printf("1) Place New Order\n");
        printf("2) Complete Order\n");
        printf("3) Display Active Orders\n");
        printf("4) Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (option) {
            case 1:
                newOrder();
                break;
            case 2:
                completedOrder();
                break;
            case 3:
                displayOrders();
                break;
            case 4:
                printf("Exiting Program. Goodbye!\n");
                f = 0;
                break;
            default:
                printf("Invalid Input! Please select options 1-4.\n");
                break;
        }
    } while (f);

    return 0;
}