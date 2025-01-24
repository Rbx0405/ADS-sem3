#include <stdio.h>

int main()
{
    // Declare an array of size 5
    int arr[5] = {10, 20, 30, 40, 50};

    // Print the array elements
    printf("Array elements:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}