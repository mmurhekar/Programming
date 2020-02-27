// 1. Find First Ocurrance of an element in a Sorted Array.
// 2. Find Last Ocurrance of an element in a Sorted Array.
// Time Complexity: O(log n)

#include <stdio.h>

int FirstOcurranceBinarySearch(int *A, int n, int key)
{
    int mid, low, high;
    int FirstIndex;

    FirstIndex = -1;
    low = 0;
    high = n - 1;

    while (low < high)
    {
        mid = low + (high - low) / 2;

        if ( A[mid] == key )
        {
            FirstIndex = mid;
            // Search on the left sub Array.
            high = mid - 1;
        }
        else if (A[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return FirstIndex;
}

int LastOcurranceBinarySearch(int *A, int n, int key)
{
    int mid, low, high;
    int LastIndex;

    LastIndex = -1;
    low = 0;
    high = n - 1;

    while (low < high)
    {
        mid = low + (high - low) / 2;

        if ( A[mid] == key )
        {
            LastIndex = mid;
            // Search on the right sub array.
            low = mid + 1;
        }
        else if (A[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return LastIndex;
}

int main()
{
    int A[] = {1, 2, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(A)/sizeof(A[0]);
    int key, index;

    key = 3;
    // Find First Ocurrance of Key in a sorted Array.
    index = FirstOcurranceBinarySearch(A, size, key);
    printf("\n First Index of %d is %d\n", key, index);

    key = 3;
    // Find the Last Ocurrance of Key in a Sorted Array.
    index = LastOcurranceBinarySearch(A, size, key);
    printf("\n Last Index of %d is %d\n", key, index);

    return 0;
}
