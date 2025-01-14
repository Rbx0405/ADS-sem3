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
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int N, item;
    scanf("%d", &N); // Read the size of the sorted list
    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]); // Read the sorted list
    scanf("%d", &item);       // Read the item to be searched

    int index = binarySearch(arr, N, item); // Perform binary search
    printf("%d\n", index);                  // Print the index if the item is found
    return 0;
}