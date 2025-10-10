#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int deque[MAX], front = -1, rear = -1;

void insertFront(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } 
    else if (front == 0) {
        front = MAX - 1; 
    } 
    else {
        front=front-1;
    }
    deque[front] = value;
    //printf("%d inserted at the front.\n", value);
}
void insertRear(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear == front - 1)) {
        printf("Overflow.\n");
        return;
    }
    if (front == -1) { 
        front = rear = 0;
    } 
    else if (rear == MAX - 1) {
        rear = 0; 
    } 
    else {
        rear=rear+1;
    }
    deque[rear] = value;
    //printf("%d inserted at the rear.\n", value);
}
void deleteFront() {
    if (front == -1) {
        printf("Underflow.\n");
        return;
    }
    printf("Deleted element from front: %d\n", deque[front]);
    if (front == rear) { 
        front = rear = -1; 
    } 
    else if (front == MAX - 1) {
        front = 0; 
    } 
    else {
        front=front+1;
    }
}
void deleteRear() {
    if (front == -1) {
        printf("Underflow.\n");
        return;
    }
    printf("Deleted element from rear: %d\n", deque[rear]);
    if (front == rear) { 
        front = rear = -1; 
    } 
    else if (rear == 0) {
        rear = MAX - 1; 
    } 
    else {
        rear=rear-1;
    }
}
void displayElements() {
    if (front == -1) {
        printf("Dequeue is empty.\n");
        return;
    }
    printf("Dequeue elements: ");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
    } 
    else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", deque[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\nDouble Ended Queue Operations:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display elements\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                displayElements();
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
