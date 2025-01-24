#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node
{
    int data;
    struct Node *next;
};

// Insert a new node at the end
struct Node *insert(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print the linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);

    printList(head);

    return 0;
}