#include <stdio.h>
#include <string.h>
#define MAX_CUSTOMERS 10

typedef struct
{
    char name[100];
    int accountNumber;
    float balance;
} Customer;

void printCustomersWithLowBalance(Customer customers[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (customers[i].balance < 200)
        {
            printf("%s\n", customers[i].name);
        }
    }
}
void UpdateBalanceForHighBalanceCustomers(Customer customers[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (customers[i].balance > 1000)
        {
            customers[i].balance += 100;
            printf(" %d %.2f\n", customers[i].accountNumber, customers[i].balance);
        }
    }
}
// main function
int main()
{
    int i, numCustomers;
    Customer customers[MAX_CUSTOMERS];
    scanf("%d", &numCustomers);
    for (int i = 0; i < numCustomers; i++)
    {
        printf("ENter details for customer %d\n", i + 1);
        scanf("%s", customers[i].name);
        scanf("%d", &customers[i].accountNumber);
        scanf("%f", &customers[i].balance);
    }
    printCustomersWithLowBalance(customers, numCustomers);
    UpdateBalanceForHighBalanceCustomers(customers, numCustomers);
    return 0;
}