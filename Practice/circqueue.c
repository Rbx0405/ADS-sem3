#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;           // Initialize front
    rear = (rear + 1) % MAX; // Circular increment
    queue[rear] = value;
    printf("%d enqueued\n", value);
}

// Dequeue operation
int dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) // Queue becomes empty
        front = rear = -1;
    else
        front = (front + 1) % MAX; // Circular increment
    return value;
}

// Display the queue
void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    do
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);
    printf("\n");
}

// Main function
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    enqueue(50);
    enqueue(60);
    display();

    return 0;
}