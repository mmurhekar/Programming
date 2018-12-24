#include <stdio.h>
#define MAX_ELE 20

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int *arr, int n)
{
	int i, j;
	bool flag = false;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				flag = true;
			}
		}

		//Optimization over Bubble sort
		if (!flag) break;
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

	bubble_sort(array, n);
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);

	printf("\n");

	return 0;
}
