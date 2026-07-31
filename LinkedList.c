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
    struct node *next;
 };

 struct node *head = NULL, *temp, *newnode;

 void insertBeginning(){
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
    printf("Node Inserted At Beginning Sucessfully.");
 }

 void insertEnd(){
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newnode;
    }
    printf("Node Inserted At End Sucessfully.");
 
 }

 void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    temp = head;
    head = head->next;
    printf("Deleted Element: %d\n", temp->data);
    free(temp);
    printf("Node Deleted From Beginning Successfully.\n");
}

void deleteEnd() {
    struct node *prev = NULL;

    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    temp = head;

    
    if (temp->next == NULL) {
        head = NULL;
        printf("Deleted Element: %d\n", temp->data);
        free(temp);
    } else {
        // Traverse to the last node while keeping track of previous node
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("Deleted Element: %d\n", temp->data);
        free(temp);
    }
    printf("Node Deleted From End Successfully.\n");
}

void Display(){
    temp = head;
    if(head==NULL){
        printf("Linked List is Empty!");
    }else{
        while(temp!=NULL){
            printf("%d->", temp->data);
            temp = temp->next;
        }
    }
    temp = head; //Reset temp
    
    
}

int main(){
    int option, f=1;

do{
        printf("\n--- Choose the following options ---\n");
        printf("1) Enter Value at Beginning\n2) Enter Value at End\n3) Delete Value at Beginning\n4) Delete Value at End\n5) Display\n6) Exit\n");
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
            deleteBeginning();
            break;   
        case 4:
            deleteEnd();
            break;
        case 5:
            Display();
            break;       
        case 6:
            printf("Exiting Program\n");
            f=0;
            break;
        default:
            printf("Invalid Input\n");
            f=0;
            break;
        }
        printf("\n");
    }while(f == 1);
    return 0;
}