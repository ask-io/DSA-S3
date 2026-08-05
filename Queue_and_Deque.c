/*
 * AUTHOR   : Abhijit Smiju Kunnel
 * CLASS    : CSE B
 * ROLL NO  : 2
 * REG NO   : 25CS005
 */

#include <stdio.h>
#define MAX 100

// Linear Queue
int l_items[MAX];
int l_front = -1, l_rear = -1;

void l_enqueue(int x) {
    if (l_rear == MAX - 1) {
        printf("Linear Queue is Full. (Overflow)\n");
        return;
    }
    if (l_front == -1) l_front = 0;
    l_rear++;
    l_items[l_rear] = x;
    printf("Inserted: %d\n", x);
}

void l_dequeue() {
    if (l_front == -1 || l_front > l_rear) {
        printf("Linear Queue is Empty. (Underflow)\n");
        return;
    }
    printf("Deleted: %d\n", l_items[l_front]);
    l_front++;
    if (l_front > l_rear) {
        l_front = -1;
        l_rear = -1;
    }
}

void l_display() {
    if (l_front == -1 || l_front > l_rear) {
        printf("Linear Queue is Empty.\n");
        return;
    }
    printf("Linear Queue elements: ");
    for (int i = l_front; i <= l_rear; i++) {
        printf("%d ", l_items[i]);
    }
    printf("\n");
}

void linearQueueMenu() {
    int choice, val;
    while (1) {
        printf("\n--- LINEAR QUEUE MENU ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                l_enqueue(val);
                break;
            case 2:
                l_dequeue();
                break;
            case 3:
                l_display();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Double Ended Queue
int d_items[MAX];
int d_front = -1, d_rear = -1;

void d_insertFront(int x) {
    if ((d_front == 0 && d_rear == MAX - 1) || (d_front == d_rear + 1)) {
        printf("Deque is Full. (Overflow)\n");
        return;
    }
    if (d_front == -1) {
        d_front = d_rear = 0;
    } else if (d_front == 0) {
        d_front = MAX - 1;
    } else {
        d_front--;
    }
    d_items[d_front] = x;
    printf("Inserted %d at Front\n", x);
}

void d_insertRear(int x) {
    if ((d_front == 0 && d_rear == MAX - 1) || (d_front == d_rear + 1)) {
        printf("Deque is Full. (Overflow)\n");
        return;
    }
    if (d_front == -1) {
        d_front = d_rear = 0;
    } else if (d_rear == MAX - 1) {
        d_rear = 0;
    } else {
        d_rear++;
    }
    d_items[d_rear] = x;
    printf("Inserted %d at Rear\n", x);
}

void d_deleteFront() {
    if (d_front == -1) {
        printf("Deque is Empty. (Underflow)\n");
        return;
    }
    printf("Deleted %d from Front\n", d_items[d_front]);
    if (d_front == d_rear) {
        d_front = d_rear = -1;
    } else if (d_front == MAX - 1) {
        d_front = 0;
    } else {
        d_front++;
    }
}

void d_deleteRear() {
    if (d_front == -1) {
        printf("Deque is Empty. (Underflow)\n");
        return;
    }
    printf("Deleted %d from Rear\n", d_items[d_rear]);
    if (d_front == d_rear) {
        d_front = d_rear = -1;
    } else if (d_rear == 0) {
        d_rear = MAX - 1;
    } else {
        d_rear--;
    }
}

void d_display() {
    if (d_front == -1) {
        printf("Deque is Empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = d_front;
    while (1) {
        printf("%d ", d_items[i]);
        if (i == d_rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void dequeMenu() {
    int choice, val;
    while (1) {
        printf("\n--- DOUBLE ENDED QUEUE MENU ---\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                d_insertFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                d_insertRear(val);
                break;
            case 3:
                d_deleteFront();
                break;
            case 4:
                d_deleteRear();
                break;
            case 5:
                d_display();
                break;
            case 6:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Main Menu
int main() {
    int choice;
    while (1) {
        printf("\n-----------------------\n");
        printf("   Select the Queue  \n");
        printf("-----------------------\n");
        printf("1. Linear Queue\n");
        printf("2. Double Ended Queue (Deque)\n");
        printf("3. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                linearQueueMenu();
                break;
            case 2:
                dequeMenu();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}