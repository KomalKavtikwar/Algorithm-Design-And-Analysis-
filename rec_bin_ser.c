//Write a program for Iterative and Recursive Binary Search, sequential search and verify the time complexity.

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // includes the time library for measuring time taken by different //algorithms.

int BinarySearch(int a[], int low, int high, int key, int recursive);
int LinearSearch(int a[], int key, int n);

int main() {
    clock_t start, end;
    double time;
    int a[100], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the Numbers:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nEntered Numbers Are:");
    for (int i = 0; i < n; i++)
        printf("\t %d", a[i]);

    for (int i = 0; i < n; i++) //iterates over each element of the array
{
        int min = i;// stores the index of the minimum element found so far
        for (int j = i + 1; j < n; j++) // iterates over the remaining elements in arr
            if (a[min] > a[j]) //checks if the current element is smaller than the min element found so far. If yes update the min element
                min = j;

        if (min != i) { //checks if  min element is not already at its correct position.
            int temp = a[i];  //Swapping Elements
            a[i] = a[min];
            a[min] = temp;
        }
    }

    printf("\nSorted Array is:");
    for (int i = 0; i < n; i++)
        printf("\t %d", a[i]);

    int key;
    printf("\nEnter the Element to be Searched: ");
    scanf("%d", &key);

    start = clock();  // clock ticks before the function call.
    int result = LinearSearch(a, key, n);
    end = clock();  // clock ticks after the function call.
    time = ((double)(end - start)) / CLOCKS_PER_SEC;  // calculates the time difference in seconds by dividing the elapsed clock ticks by the number of clock ticks per second.
    printf("\nElement is %s at: %d and Time Taken By Linear Search: %f",
           (result == -1) ? "Absent" : "Present", result + 1, time);

    start = clock();
    result = BinarySearch(a, 0, n - 1, key, 1);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nElement is %s at: %d and Time Taken By Recursive Binary Search: %f",
           (result == -1) ? "Absent" : "Present", result + 1, time);

    start = clock();
    result = BinarySearch(a, 0, n - 1, key, 0);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nElement is %s at: %d and Time Taken By Non-Recursive Binary Search: %f\n",
           (result == -1) ? "Absent" : "Present", result + 1, time);

    return 0;
}

// low: The lower bound of the search range (inclusive).
//high: The upper bound of the search range (inclusive).
//key: The integer value to be searched for.

int BinarySearch(int a[], int low, int high, int key, int recursive) {
    while (low <= high) {
        int mid = (low + high) / 2;  // middle element of the search range (mid).
        if (a[mid] == key)
            return mid;
        else if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int LinearSearch(int a[], int key, int n) {
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

