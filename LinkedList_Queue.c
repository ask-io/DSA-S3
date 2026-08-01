// Linked Queue Implementation in C
// Enqueue at rear end and Dequeue at front
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode, *f=NULL, *r=NULL, *temp;

void en(int item)
{
    newnode= (struct node *) malloc (sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    if(f==NULL)
    {
        f=r=newnode;
    }
    else
    {
        //Insert at the rear
        r->next=newnode;
        r=newnode;
    }
}

void de()
{
  if(f==NULL)
    printf("Queue is empty");
  else
  {
      temp=f;
      if(f==r)
      //Deletion at front end
        f=r=NULL;
      else
        f=f->next;
      free(temp);
      
  }
}

void display()
{
    temp=f;
    if(f==NULL)
        printf("\nQueue is empty");
    else
    {
        while(temp!=NULL)
        {
            printf("\t%d\t",temp->data);
            temp=temp->next;
        }
    }
}

int main() {
    int choice, value, ch;
    do
    {
        printf("\nEnter choice 1. Enqueue 2. Dequeue 3. Display 4. Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("\nEnter value to insert :");
                     scanf("%d",&value);
                     en(value);
                     break;
            case 2 : de();
                     break;
            case 3:  display();
                      break;
            case 4 : exit(0);
                     break;
            default: printf("\nInvalid case");
        }
        printf("\nPress 1 to continue :");
        scanf("%d",&ch);
    }while(ch==1);
    return 0;
}