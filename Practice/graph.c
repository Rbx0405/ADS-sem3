#include <stdio.h>
#include <stdlib.h>

#define V 4 // Number of vertices

// Define a structure for adjacency list nodes
struct Node
{
    int vertex;
    struct Node *next;
};

// Define a structure for the graph
struct Graph
{
    int vertices;
    struct Node *adjList[V];
};

// Create a new node
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph *createGraph()
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = V;

    for (int i = 0; i < V; i++)
    {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Add edge
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Display the graph
void displayGraph(struct Graph *graph)
{
    printf("Adjacency List:\n");
    for (int i = 0; i < V; i++)
    {
        printf("Vertex %d: ", i);
        struct Node *temp = graph->adjList[i];
        while (temp)
        {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Graph *graph = createGraph();

    // Add edges manually
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    displayGraph(graph);

    return 0;
}