#include <stdio.h>
#define MAX 10

int graph[MAX][MAX]; // Adjacency matrix
int visited[MAX];    // Visited array
int nodes;           // Number of nodes

void DFS(int start)
{
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < nodes; i++)
    {
        if (graph[start][i] == 1 && !visited[i])
        {
            DFS(i);
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

    printf("DFS Traversal: ");
    DFS(0); // Start DFS from node 0
    return 0;
}