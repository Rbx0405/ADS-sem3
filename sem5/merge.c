#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int L[n1], R[n2];
    
    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Main merge sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to fill array with random numbers between 1 and 100
void randomizeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) + 1;  // Random number between 1 and 100
    }
}

// Main function
int main() {
    srand(time(NULL));  // Seed random number generator
    
    int arr[10];  // Array of 10 elements
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Fill array with random numbers
    randomizeArray(arr, n);
    
    printf("Original array: \n");
    printArray(arr, n);
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
