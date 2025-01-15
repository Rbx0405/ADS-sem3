#include <stdio.h>
int main()
{
    int i, arr[100];
    int n = 0, ind, choice, x, isRunning = 1;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("1. Insert a number\n");
    printf("2. Delete a number\n");
    printf("3. Display the array\n");
    printf("4. Exit\n");
    while (isRunning)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number: ");
            scanf("%d", &x);
            printf("Enter location: ");
            scanf("%d", &ind);
            if (ind < 0 || ind > n)
                printf("Location not found\n");
            else
            {
                for (int i = n - 1; i >= ind; i--)
                {
                    arr[i + 1] = arr[i];
                }
                arr[ind] = x;
                n++;
            }
            break;
        case 2:
            printf("Enter location: ");
            scanf("%d", &ind);
            if (ind < 0 || ind > n)
                printf("Location not found\n");
            else
            {
                for (i = ind; i < n - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                n--;
            }
            break;
        case 3:
            printf("Array elements: ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 4:
            isRunning = 0;
            break;
        default:
            printf("Invalid input!");
        }
    }
}
