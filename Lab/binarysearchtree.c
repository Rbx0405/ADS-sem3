#include <stdio.h>

int binarySearch(int arr[], int n, int item)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        printf("%d\n", arr[mid]);
        if (arr[mid] == item)
        {
            return mid;
        }
        else if (arr[mid] < item)
        {
            return mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
// main
int main()
{
    int N, item;

    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];

    printf("Enter %d elements (sorted in ascending order):\n", N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the item to search: ");
    scanf("%d", &item);

    int index = binarySearch(arr, N, item);

    if (index != -1)
    {
        printf("Item found at index %d\n", index);
    }
    else
    {
        printf("Item not found in the array\n");
    }

    return 0;
}