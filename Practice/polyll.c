#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node
{
    int coeff, exp;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int coeff, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert a term at the end
struct Node *insertTerm(struct Node *head, int coeff, int exp)
{
    struct Node *newNode = createNode(coeff, exp);
    if (!head)
        return newNode;

    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Add two polynomials
struct Node *addPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;

    while (poly1 || poly2)
    {
        if (!poly2 || (poly1 && poly1->exp > poly2->exp))
        {
            result = insertTerm(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else if (!poly1 || (poly2 && poly1->exp < poly2->exp))
        {
            result = insertTerm(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        else
        {
            result = insertTerm(result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    return result;
}

// Print a polynomial
void printPolynomial(struct Node *poly)
{
    while (poly)
    {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

// Main function
int main()
{
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;

    // Polynomial 1: 5x^2 + 4x + 2
    poly1 = insertTerm(poly1, 5, 2);
    poly1 = insertTerm(poly1, 4, 1);
    poly1 = insertTerm(poly1, 2, 0);

    // Polynomial 2: 3x^2 + 2x + 1
    poly2 = insertTerm(poly2, 3, 2);
    poly2 = insertTerm(poly2, 2, 1);
    poly2 = insertTerm(poly2, 1, 0);

    // Add the polynomials
    struct Node *result = addPolynomials(poly1, poly2);

    // Print the polynomials
    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    printf("Sum: ");
    printPolynomial(result);

    return 0;
}