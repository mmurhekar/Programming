// Print all subsets of an array with a sum equal to zero
// 
// 1. Sort the given array in acesnding order
// 2. find the subsets by picking one by one element(Recursion).
//-----------------------------------------------------------------
#include <stdio.h>

void InsertionSort(int* A, int n)
{
	int i, j, key;

	for (i = 0; i < n; i++)
	{
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}

void findSubSets(int* A, int size, int sum, int* B, int count, int start)
{
	if (sum == 0 && count > 0)
	{
		for (int i = 0; i < count; i++)
			printf("%d ", B[i]);
		printf("\n");
	}

	for (int i = start; i < size; i++)
	{
		// since array is sorted so no need to check further
		// if sum is not zero
		if (sum + A[i] > 0)
			break;

		B[count] = A[i];
		findSubSets(A, size, sum + A[i], B, count + 1, i+1);
	}
}

int main()
{
	int A[] = { 8, 3, 5, 1, -4, -8 };
	int n = sizeof(A) / sizeof(A[0]);
	int B[20];

	InsertionSort(A, n);
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	findSubSets(A, n, 0, B, 0, 0);

	return 0;
}
