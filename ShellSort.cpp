// Implement Shell Sort Algo.
// Similar to inserstion sort.

#include <stdio.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void ShellSort(int* A, int n)
{
	for (int gap = n / 2; gap >= 1; gap = gap / 2)
	{
		for (int j = gap; j < n; j++)
		{
			for (int i = j - gap; i >= 0; i = i - gap)
			{
				if (A[i + gap] > A[i])
					break;

				swap(&A[i + gap], &A[i]);
			}
		}
	}
}

int main()
{
	int arr[] = { 20, 12, 34, 54, 25, 2, 3, 55, -1, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);

	ShellSort(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}