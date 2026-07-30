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