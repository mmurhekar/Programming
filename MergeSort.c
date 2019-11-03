/*
 * MergeSort
 * Divide and Conquer method */

#include <stdio.h>

#include "MeregeSort.h"

#define MAX_ELE 20

/*
 * arr = 34 5 0 2 1 10 3 */

static void merge(int *arr, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int lt[100], rt[100], i, j, k;

	for (i = 0; i < n1; i++)
		lt[i] = arr[l + i];

	for (j = 0; j < n2; j++)
		rt[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (lt[i] <= rt[j]) {
			arr[k] = lt[i];
			i++;
		} else {
			arr[k] = rt[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
			arr[k] = lt[i];
			i++;
			k++;
	}

	while (j < n2) {
			arr[k] = rt[j];
			j++;
			k++;
	}
}

void mergesort(int *arr, int l, int r)
{
	int mid;
	if (l < r) {
		mid = l + (r - l)/2;
		mergesort(arr, l, mid);
		mergesort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}

int main ()
{
	int array[] = {-2, 0, -9, 45, 11, 4, 10};
	int n = sizeof(array)/sizeof(array[0]), i;

	printf("\n");

	for (i = 0; i < n; i++)
		printf("%d ", array[i]);

	printf("\n");

	mergesort(array, 0, n-1);

	for (i = 0; i < n; i++)
		printf("%d ", array[i]);

	printf("\n");

	return 0;
}
