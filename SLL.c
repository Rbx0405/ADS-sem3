#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student node
typedef struct Node
{
    char USN[10];
    char Name[20];
    char Branch[10];
    int Sem;
    char PhNo[10];
    struct Node *next;
} Node;

// Global variables
Node *head = NULL; // Global head pointer
Node *temp;        // Global temporary pointer

// Function to create a new node
Node *createNode()
{
    Node *nn = (Node *)malloc(sizeof(Node));                                    // Allocate memory for new node
    scanf("%s %s %s %d %s", nn->USN, nn->Name, nn->Branch, &nn->Sem, nn->PhNo); // Read data
    nn->next = NULL;                                                            // Initialize next as NULL
    return nn;
}

// Function to insert a node at the front of the list
void insertAtFront()
{
    Node *nn = createNode(); // Create new node
    nn->next = head;         // Point new node to current head
    head = nn;               // Update head to point to the new node
}

// Function to insert a node at the end of the list
void insertAtEnd()
{
    Node *nn = createNode(); // Create new node
    if (head == NULL)
    { // If the list is empty
        head = nn;
        return;
    }
    temp = head; // Temporary pointer to traverse the list
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nn; // Add the new node at the end
}

// Function to delete a node from the front of the list
void deleteAtFront()
{
    if (head == NULL)
    { // If the list is empty
        printf("List is empty.\n");
        return;
    }
    temp = head;       // Store the current head
    head = head->next; // Update head to the next node
    free(temp);        // Free memory of the old head
}

// Function to delete a node from the end of the list
void deleteAtEnd()
{
    if (head == NULL)
    { // If the list is empty
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL)
    { // If there is only one node
        free(head);
        head = NULL;
        return;
    }
    temp = head; // Temporary pointer to traverse the list
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);  // Free memory of the last node
    temp->next = NULL; // Update the second last node
}

// Function to display the list and count the number of nodes
void displayList()
{
    int count = 0;
    temp = head; // Temporary pointer to traverse the list
    while (temp != NULL)
    {
        printf("%s ", temp->Name); // Print student name
        count++;
        temp = temp->next;
    }
    printf("\nNumber of nodes: %d\n", count);
}

// Main function
int main()
{
    int choice, n;
    while (1)
    {
        printf("Menu:\n");
        printf("1. Create SLL of N Students Data\n");
        printf("2. Display and count the number of nodes\n");
        printf("3. Perform Insertion at End of SLL\n");
        printf("4. Perform Insertion at Front of SLL\n");
        printf("5. Perform Deletion at End of SLL\n");
        printf("6. Perform Deletion at Front of SLL\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of students: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                insertAtFront();
            }
            break;
        case 2:
            displayList();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtFront();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtFront();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
