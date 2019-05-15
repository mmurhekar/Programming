#include <stdio.h>

#include "QuickSort.h"

#define MAX_ELE 20

static void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

static int partition(int *arr, int low, int high)
{
	int pivot;
	int i, j;

	pivot = arr[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

void quicksort(int *arr, int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}
#if 0
int main ()
{
	int array[] = {-2, 0, -9, 45, 55, 67, 90, 2, 1, 5, 11, 4, 10, -100, 100};
	int n = sizeof(array)/sizeof(array[0]), i;

	printf("\n");

	for (i = 0; i < n; i++)
		printf("%d ", array[i]);

	printf("\n");

	quicksort(array, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d ", array[i]);

	printf("\n");

	return 0;
}
#endif
