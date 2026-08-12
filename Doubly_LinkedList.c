/*
 * AUTHOR  : Abhijit Smiju Kunnel
 * CLASS   : CSE B
 * ROLL NO : 2
 * REG NO  : 25CS005
 
 */
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void insertBeginning(){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;     //Checking if empty
        tail = newnode;
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("Node Inserted At Beginning Successfully.\n");
}

void insertEnd(){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    printf("Node Inserted At End Successfully.\n");
}

void insertAtPosition(){
    int pos, i = 1;
    printf("Enter Position: ");
    scanf("%d", &pos);

    if(pos < 1){
        printf("Invalid position!\n");
        return;
    }

    if(pos == 1){       //If pos is beginning
        insertBeginning();
        return;
    }

    struct node *temp = head;
    while(i < pos - 1 && temp != NULL){
        temp = temp->next;
        i++;
    }

    if(temp == NULL){
        printf("Previous position doesn't exist. Insertion failed.\n");
    } else if(temp->next == NULL) {
        // If inserting at the very end
        insertEnd();
    } else {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);

        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
        printf("Node Inserted At Position %d Successfully.\n", pos);
    }
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    struct node *temp = head;
    printf("Deleted Element: %d\n", temp->data);

    if(head == tail) { // Only one node in the list
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
    printf("Node Deleted From Beginning Successfully.\n");
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct node *temp = tail;
    printf("Deleted Element: %d\n", temp->data);

    if(head == tail) { // Only one node in the list
        head = NULL;
        tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
    printf("Node Deleted From End Successfully.\n");
}

void deleteAtPosition() {
    int pos, i = 1;

    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    printf("Enter Position to Delete: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    struct node *temp = head;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
    } else if (temp == tail) {
        deleteEnd();
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        printf("Deleted Element: %d\n", temp->data);
        free(temp);
        printf("Node Deleted From Position %d Successfully.\n", pos);
    }
}

void Display(){
    struct node *temp = head;
    if(head == NULL){
        printf("Linked List is Empty!\n");
    } else {
        printf("NULL <-> ");
        while(temp != NULL){
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    int option, f = 1;

    do{
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1) Enter Value at Beginning\n");
        printf("2) Enter Value at End\n");
        printf("3) Enter Value at Specific Position\n");
        printf("4) Delete Value at Beginning\n");
        printf("5) Delete Value at End\n");
        printf("6) Delete Value at Specific Position\n");
        printf("7) Display\n");
        printf("8) Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            insertBeginning();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
            deleteBeginning();
            break;   
        case 5:
            deleteEnd();
            break;
        case 6:
            deleteAtPosition();
            break;
        case 7:
            Display();
            break;      
        case 8:
            printf("Exiting Program\n");
            f = 0;
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }while(f == 1);
    
    return 0;
}