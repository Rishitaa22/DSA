#include <stdio.h>
#define Max 5

int queue[Max];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == Max - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
    printf("%d enqueued to queue\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d dequeued from queue\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
        } 
        else if (choice == 2) {
            dequeue();
        } 
        else if (choice == 3) {
            display();
        } 
        else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } 
        else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

