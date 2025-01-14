#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
    int data[MAX];
    int top;
} Stack;

void initialize(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX - 1;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
        printf("Stack overflow\n");
    else
        stack->data[++stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

void displayStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++)
        {
            printf("%d ", stack->data[i]);
        }
        printf("\n");
    }
}

void checkPalindrome(char *str)
{
    int i, n = strlen(str);
    Stack stack;
    initialize(&stack);
    int pal = 1;
    for (i = 0; i < n; i++)
        push(&stack, str[i]);
    for (i = 0; i < n; i++)
    {
        if (pop(&stack) != str[i])
            pal = 0;
    }
    if (pal)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
}

int main()
{
    Stack stack;
    initialize(&stack);

    int choice, value;
    char str[MAX];

    while (1)
    {
        printf("Menu:\n");
        printf("1. Push an element onto stack\n");
        printf("2. Pop an element from stack\n");
        printf("3. Check if a string is a palindrome\n");
        printf("4. Display stack status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter an integer to push onto stack: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            value = pop(&stack);
            if (value != -1)
            { // Check for underflow
                printf("Popped value: %d\n", value);
            }
            break;
        case 3:
            printf("Enter a string to check palindrome: ");
            scanf("%s", str);
            checkPalindrome(str);
            break;
        case 4:
            displayStack(&stack);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
