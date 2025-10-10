import java.util.Random;
import java.util.Scanner;
import java.util.Arrays;

public class MergeSort {
    
    /**
     * Sorts an array using the merge sort algorithm.
     * 
     * @param arr The array to be sorted
     * @param left Starting index
     * @param right Ending index
     */
    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            // Find the middle point
            int mid = left + (right - left) / 2;
            
            // Sort first and second halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            
            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }
    
    /**
     * Merges two subarrays of arr[].
     * First subarray is arr[left..mid]
     * Second subarray is arr[mid+1..right]
     * 
     * @param arr The array containing both subarrays
     * @param left Starting index of first subarray
     * @param mid Ending index of first subarray
     * @param right Ending index of second subarray
     */
    public static void merge(int[] arr, int left, int mid, int right) {
        // Find sizes of two subarrays to be merged
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        // Create temporary arrays
        int[] leftArray = new int[n1];
        int[] rightArray = new int[n2];
        
        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++) {
            leftArray[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArray[j] = arr[mid + 1 + j];
        }
        
        // Merge the temporary arrays
        int i = 0, j = 0;
        int k = left; // Initial index of merged subarray
        
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                arr[k] = leftArray[i];
                i++;
            } else {
                arr[k] = rightArray[j];
                j++;
            }
            k++;
        }
        
        // Copy remaining elements of leftArray[] if any
        while (i < n1) {
            arr[k] = leftArray[i];
            i++;
            k++;
        }
        
        // Copy remaining elements of rightArray[] if any
        while (j < n2) {
            arr[k] = rightArray[j];
            j++;
            k++;
        }
    }
    
    /**
     * Generates an array of random integers between 1 and 100
     * 
     * @param size The size of the array to generate
     * @return Array of random integers
     */
    public static int[] generateRandomArray(int size) {
        Random random = new Random();
        int[] arr = new int[size];
        
        for (int i = 0; i < size; i++) {
            arr[i] = random.nextInt(100) + 1; // Random number from 1 to 100
        }
        
        return arr;
    }
    
    /**
     * Prints an array in a formatted way
     * 
     * @param arr The array to print
     * @param label Label to display before the array
     */
    public static void printArray(int[] arr, String label) {
        System.out.print(label + ": ");
        if (arr.length <= 50) {
            // Print full array if it's small
            System.out.println(Arrays.toString(arr));
        } else {
            // Print first 20 and last 20 elements for large arrays
            System.out.print("[");
            for (int i = 0; i < 20; i++) {
                System.out.print(arr[i]);
                if (i < 19) System.out.print(", ");
            }
            System.out.print(" ... ");
            for (int i = arr.length - 20; i < arr.length; i++) {
                System.out.print(arr[i]);
                if (i < arr.length - 1) System.out.print(", ");
            }
            System.out.println("]");
            System.out.println("Array size: " + arr.length + " elements");
        }
    }
    
    /**
     * Converts nanoseconds to seconds with appropriate formatting
     * 
     * @param nanoseconds Time in nanoseconds
     * @return Formatted time string
     */
    public static String formatTime(long nanoseconds) {
        double seconds = nanoseconds / 1_000_000_000.0;
        
        if (seconds < 0.001) {
            return String.format("%.6f seconds (%.3f ms)", seconds, seconds * 1000);
        } else if (seconds < 1) {
            return String.format("%.6f seconds (%.2f ms)", seconds, seconds * 1000);
        } else {
            return String.format("%.6f seconds", seconds);
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("=== Merge Sort with Random Numbers ===");
        System.out.print("Enter the number of elements in the array: ");
        
        int size;
        try {
            size = scanner.nextInt();
            if (size <= 0) {
                System.out.println("Please enter a positive number.");
                scanner.close();
                return;
            }
        } catch (Exception e) {
            System.out.println("Invalid input. Please enter a valid number.");
            scanner.close();
            return;
        }
        
        System.out.println("\nGenerating array with " + size + " random numbers (1-100)...");
        int[] arr = generateRandomArray(size);
        
        printArray(arr, "Original array");
        
        int[] sortedArr = arr.clone();
        
        System.out.println("\nSorting array using Merge Sort...");
        long startTime = System.nanoTime();
        
        mergeSort(sortedArr, 0, sortedArr.length - 1);
        
        long endTime = System.nanoTime();
        long executionTime = endTime - startTime;
        
        System.out.println("Sorting completed!");
        printArray(sortedArr, "Sorted array");
        
        System.out.println("\n=== Performance Results ===");
        System.out.println("Array size: " + size + " elements");
        System.out.println("Execution time: " + formatTime(executionTime));
        
        if (size >= 1000) {
            double elementsPerSecond = size / (executionTime / 1_000_000_000.0);
            System.out.println("Processing rate: " + String.format("%.0f", elementsPerSecond) + " elements/second");
        }
        
        scanner.close();
    }
}
