#include <stdio.h>
#define MAX 10

int graph[MAX][MAX]; // Adjacency matrix
int visited[MAX];    // Visited array
int queue[MAX];      // Queue for BFS
int front = -1, rear = -1;
int nodes; // Number of nodes

void enqueue(int value)
{
    if (rear == MAX - 1)
        return; // Queue Overflow
    if (front == -1)
        front = 0; // Initialize front
    queue[++rear] = value;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1; // Queue Underflow
    return queue[front++];
}

void BFS(int start)
{
    enqueue(start);
    visited[start] = 1;

    while (front <= rear)
    {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < nodes; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    nodes = 5; // Example: 5 nodes (0 to 4)

    // Example adjacency matrix
    int tempGraph[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}};

    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            graph[i][j] = tempGraph[i][j];

    printf("BFS Traversal: ");
    BFS(0); // Start BFS from node 0
    return 0;
}