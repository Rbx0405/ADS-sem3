#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an employee node
typedef struct Employee
{
    int ssn;
    int sal;
    char Name[100];
    char dept[50];
    char designation[50];
    char phone[15];
    struct Employee *next;
    struct Employee *prev;
} Node;

// Global pointers for head and tail
Node *head = NULL;
Node *tail = NULL;

// Function to create a new node
Node *createNode()
{
    Node *nn = (Node *)malloc(sizeof(Node));
    printf("Enter Employee Details (SSN Name Department Designation Salary Phone):\n");
    scanf("%d", &nn->ssn);
    scanf("%s", nn->Name);
    scanf("%s", nn->dept);
    scanf("%s", nn->designation);
    scanf("%d", &nn->sal);
    scanf("%s", nn->phone);
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}

// Function to insert a node at the end of the DLL
void insertAtEnd()
{
    Node *nn = createNode();
    if (head == NULL)
    { // If the list is empty
        head = tail = nn;
    }
    else
    {
        tail->next = nn;
        nn->prev = tail;
        tail = nn;
    }
}

// Function to insert a node at the front of the DLL
void insertAtFront()
{
    Node *nn = createNode();
    if (head == NULL)
    { // If the list is empty
        head = tail = nn;
    }
    else
    {
        nn->next = head;
        head->prev = nn;
        head = nn;
    }
}

// Function to delete a node from the end of the DLL
void deleteAtEnd()
{
    if (tail == NULL)
    { // If the list is empty
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    Node *temp = tail;
    if (head == tail)
    { // If there's only one node
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
    printf("Node deleted from the end.\n");
}

// Function to delete a node from the front of the DLL
void deleteAtFront()
{
    if (head == NULL)
    { // If the list is empty
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    Node *temp = head;
    if (head == tail)
    { // If there's only one node
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
    printf("Node deleted from the front.\n");
}

// Function to display the DLL and count the number of nodes
void displayDLL()
{
    int count = 0;
    Node *temp = head;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Employee Details:\n");
    while (temp != NULL)
    {
        printf("SSN: %d, Name: %s, Dept: %s, Designation: %s, Salary: %d, Phone: %s\n",
               temp->ssn, temp->Name, temp->dept, temp->designation, temp->sal, temp->phone);
        count++;
        temp = temp->next;
    }
    printf("Total number of nodes: %d\n", count);
}

// DEQ Operations

// Enqueue Front
void enqueueFront()
{
    insertAtFront();
    printf("Node enqueued at the front.\n");
}

// Enqueue Back
void enqueueBack()
{
    insertAtEnd();
    printf("Node enqueued at the back.\n");
}

// Dequeue Front
void dequeueFront()
{
    deleteAtFront();
}

// Dequeue Back
void dequeueBack()
{
    deleteAtEnd();
}

// Main function
int main()
{
    int choice, n;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Create DLL of N Employees Data\n");
        printf("2. Display the status of DLL and count the number of nodes\n");
        printf("3. Perform Insertion at End of DLL\n");
        printf("4. Perform Insertion at Front of DLL\n");
        printf("5. Perform Deletion at End of DLL\n");
        printf("6. Perform Deletion at Front of DLL\n");
        printf("7. Enqueue Front (DEQ)\n");
        printf("8. Enqueue Back (DEQ)\n");
        printf("9. Dequeue Front (DEQ)\n");
        printf("10. Dequeue Back (DEQ)\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of employees: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                insertAtEnd();
            }
            break;
        case 2:
            displayDLL();
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
            enqueueFront();
            break;
        case 8:
            enqueueBack();
            break;
        case 9:
            dequeueFront();
            break;
        case 10:
            dequeueBack();
            break;
        case 11:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
