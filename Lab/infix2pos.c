#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct
{
    char data[MAX];
    int top;
} Stack;

// Function prototypes
void push(Stack *stack, char item);
char pop(Stack *stack);
int precedence(char operator);
int isOperator(char ch);
void infixToPostfix(char *infix, char *postfix);

// Push an element onto the stack
void push(Stack *stack, char item)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack->data[++stack->top] = item;
}

// Pop an element from the stack
char pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Return the precedence of operators
int precedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

// Check if a character is an operator
int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Convert infix to postfix
void infixToPostfix(char *infix, char *postfix)
{
    Stack stack;
    stack.top = -1;
    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0')
    {
        ch = infix[i];

        // If the character is an operand, add it to postfix
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        // If the character is '(', push it onto the stack
        else if (ch == '(')
        {
            push(&stack, ch);
        }
        // If the character is ')', pop and output until '(' is encountered
        else if (ch == ')')
        {
            while (stack.top != -1 && stack.data[stack.top] != '(')
            {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop the '('
        }
        // If the character is an operator
        else if (isOperator(ch))
        {
            while (stack.top != -1 && precedence(stack.data[stack.top]) >= precedence(ch))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
        i++;
    }

    // Pop all remaining operators from the stack
    while (stack.top != -1)
    {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Main function to test the program
int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}