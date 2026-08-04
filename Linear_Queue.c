/*

 * AUTHOR  : Abhijit Smiju Kunnel
 * CLASS   : CSE B
 * ROLL NO : 2
 * REG NO  : 25CS005
 
 */

 #include <stdio.h>
 #define MAX 100

 int items[MAX];
 int front = -1;
 int rear = -1;

 void enqueue(int x){
    if(rear == MAX-1){
        printf("The Queue is Full. (Overflow)\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    items[rear] = x;
    printf("Inserted: %d\n", x);
 }

 void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue is Empty. (Underflow)\n");
        return;
    }
    int x = items[front];
    printf("Deleted: %d\n", x);
    front++;
    if(front > rear){
        front = -1;
        rear = -1;
    }
 }

 void display(){
    if(front == -1 || front > rear){
        printf("Queue is Empty.\n");
        return;
    }
    printf("Queue elements: ");
    for(int i = front; i <= rear; i++){
        printf("%d ", items[i]);
    }
    printf("\n");
 }

 int main(){
    int choice, value;
    while(1){
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
 }