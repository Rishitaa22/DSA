#include <stdio.h>
int front = -1;
int rear = -1;
int max;

void display(int queue[]) {
    if (front == -1) {
        printf("Queue is empty.\n");
    }
    else if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
    else {
        for (int i = front; i <= max - 1; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void enqueue(int queue[], int value) {
    if ((rear + 1) % max == front) {
        printf("Queue is full (Overflow).\n");
    }
    else {
        if (front == -1) {
            front = rear = 0;
            queue[rear] = value;
        }
        else {
            rear = (rear + 1) % max;
            queue[rear] = value;
        }
        display(queue);  
    }
}

void dequeue(int queue[]) {
    if (front == -1) {
        printf("Queue is empty (Underflow).\n");
    }
    else {
        printf("Deleted: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % max;  
        }
        display(queue); 
    }
}

int main() {
    int choice, value;
    printf("Enter the size of the queue: ");
    scanf("%d", &max);
    int queue[max];

    while (1) {
        printf("\nChoose an operation:\n 1. Enqueue\n 2. Dequeue\n 3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                printf("Exited.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

