#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define STACK_MAX_SIZE 20
// Declare the required stack variables.
int stack[STACK_MAX_SIZE];
int top = -1;

// Return 1 if stack is empty else return 0.
int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

// Push the character into stack
void push(int x)
{
    stack[++top] = x;
}

// pop a character from stack
int pop()
{
    return stack[top--];
}

// Output Format - Result : <result> if the input postfix expression is vaild.
// Output Format - Invalid postfix expression,. - if the input expression is invalid.
// postfix expression is given as the parameter.
void evaluatePostfix(char *e)
{
    int res, len = strlen(e), a, b, temp;
    for (int i = 0; i < len; i++)
    {
        if (isdigit(e[i]))
        {
            push(e[i] - '0');
        }
        else
        {
            if (isEmpty())
            {
                printf("Invalid postfix expression.\n");
                return;
            }
            else
            {
                b = pop();
                if (isEmpty())
                {
                    printf("Invalid postfix expression.\n");
                    return;
                }
                a = pop();
            }
            switch (e[i])
            {
            case '+':
                temp = a + b;
                break;
            case '-':
                temp = a - b;
                break;
            case '*':
                temp = a * b;
                break;
            case '/':
                temp = a / b;
                break;
            case '^':
                temp = pow(a, b);
                break;
            case '%':
                temp = a % b;
                break;
            default:
                printf("Invalid postfix expression.\n");
                return;
            }
            push(temp);
        }
    }
    res = pop();
    if (!isEmpty())
    {
        printf("Invalid postfix expression.\n");
        return;
    }
    printf("Result : %d\n", res);
    return;
}
// Read a postfix expression and evaluate it.
int main()
{
    char exp[20];
    char *e, x;
    printf("Enter the postfix expression : ");
    scanf("%s", exp);
    e = exp;
    evaluatePostfix(e);
    return 0;
}
