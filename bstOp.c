#include <stdio.h>
#include <stdlib.h>

// Define the node structure for BST
struct node
{
    int data;
    struct node *left, *right;
};

typedef struct node *BSTNODE;

// Function to create a new BST node
BSTNODE newNodeInBST(int item)
{
    BSTNODE temp = (BSTNODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// In-order traversal
void inorderInBST(BSTNODE root)
{
    if (root != NULL)
    {
        inorderInBST(root->left);
        printf("%d ", root->data);
        inorderInBST(root->right);
    }
}

// Pre-order traversal
void preorderInBST(BSTNODE root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderInBST(root->left);
        preorderInBST(root->right);
    }
}

// Post-order traversal
void postorderInBST(BSTNODE root)
{
    if (root != NULL)
    {
        postorderInBST(root->left);
        postorderInBST(root->right);
        printf("%d ", root->data);
    }
}

// Insert a new node into the BST
BSTNODE insertNodeInBST(BSTNODE node, int ele)
{
    if (node == NULL)
    {
        printf("Successfully inserted.\n");
        return newNodeInBST(ele);
    }
    if (ele < node->data)
    {
        node->left = insertNodeInBST(node->left, ele);
    }
    else if (ele > node->data)
    {
        node->right = insertNodeInBST(node->right, ele);
    }
    else
    {
        printf("Element already exists in the BST.\n");
    }
    return node;
}

// Search for an element in the BST
BSTNODE searchNodeInBST(BSTNODE root, int ele)
{
    if (root == NULL || root->data == ele)
    {
        return root;
    }
    if (ele < root->data)
    {
        return searchNodeInBST(root->left, ele);
    }
    return searchNodeInBST(root->right, ele);
}

int main()
{
    int x, op;
    BSTNODE root = NULL;

    while (1)
    {
        printf("\n1. Insert\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n5. Search an element\n6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Enter an element to be inserted: ");
            scanf("%d", &x);
            root = insertNodeInBST(root, x);
            break;
        case 2:
            if (root == NULL)
            {
                printf("Binary Search Tree is empty.\n");
            }
            else
            {
                printf("Elements of the BST (in-order traversal): ");
                inorderInBST(root);
                printf("\n");
            }
            break;
        case 3:
            if (root == NULL)
            {
                printf("Binary Search Tree is empty.\n");
            }
            else
            {
                printf("Elements of the BST (pre-order traversal): ");
                preorderInBST(root);
                printf("\n");
            }
            break;
        case 4:
            if (root == NULL)
            {
                printf("Binary Search Tree is empty.\n");
            }
            else
            {
                printf("Elements of the BST (post-order traversal): ");
                postorderInBST(root);
                printf("\n");
            }
            break;
        case 5:
            printf("Enter an element to be searched: ");
            scanf("%d", &x);
            if (searchNodeInBST(root, x) == NULL)
            {
                printf("Element not found in the binary search tree.\n");
            }
            else
            {
                printf("Element found in the binary search tree.\n");
            }
            break;
        case 6:
            printf("Exiting program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}