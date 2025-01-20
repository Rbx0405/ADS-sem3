#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int degree;
    struct Node *next;
};

struct Node *createNode(int coeff, int degree)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->degree = degree;
    newNode->next = NULL;
    return newNode;
}
struct Node *insertNode(struct Node *tail, int coeff, int degree)
{
    struct Node *newNode = createNode(coeff, degree);

    if (tail == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    struct Node *head = tail->next;

    if (degree > head->degree)
    {
        newNode->next = head;
        tail->next = newNode;
        return tail;
    }
    struct Node *curr = head;
    while (curr->next != head && curr->next->degree >= degree)
    {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    if (curr == tail)
    {
        tail = newNode;
    }
    return tail;
}

void displayPolynomial(struct Node *tail)
{
    if (tail == NULL)
    {
        printf("0\n");
        return;
    }
    struct Node *temp = tail->next;
    do
    {
        printf("%dx^%d", temp->coeff, temp->degree);
        temp = temp->next;
        if (temp != tail->next)
        {
            printf(" + ");
        }
    } while (temp != tail->next);
    printf("\n");
}
struct Node *addPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL, *temp1 = poly1, *temp2 = poly2;
    do
    {
        if (temp1->degree > temp2->degree)
        {
            result = insertNode(result, temp1->coeff, temp1->degree);
            temp1 = temp1->next;
        }
        else if (temp1->degree < temp2->degree)
        {
            result = insertNode(result, temp2->coeff, temp2->degree);
            temp2 = temp2->next;
        }
        else
        {
            int sumcoef = temp1->coeff + temp2->coeff;
            if (sumcoef != 0)
            {
                result = insertNode(result, sumcoef, temp1->degree);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    } while (temp1 != poly1 || temp2 != poly2);
    while (temp1 != poly1)
    {
        result = insertNode(result, temp1->coeff, temp1->degree);
        temp1 = temp1->next;
    }
    while (temp2 != poly2)
    {
        result = insertNode(result, temp2->coeff, temp2->degree);
        temp2 = temp2->next;
    }
    return result;
}
int main()
{
    int n1, n2, coeff, degree;
    struct Node *poly1 = NULL, *poly2 = NULL;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d %d", &coeff, &degree);
        poly1 = insertNode(poly1, coeff, degree);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d %d", &coeff, &degree);
        poly2 = insertNode(poly2, coeff, degree);
    }
    displayPolynomial(poly1);
    displayPolynomial(poly2);
    struct Node *result = addPolynomials(poly1, poly2);
    displayPolynomial(result);
    return 0;
}
