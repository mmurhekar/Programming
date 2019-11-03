// RADIX SORT

#include <stdio.h>

int getMax(int* A, int n)
{
	int indx = 0;
	for (int i = 1; i < n; i++)
	{
		if (A[i] > A[indx])
			indx = i;
	}

	return A[indx];
}

void CountSort(int* A, int n, int exp)
{
	int output[100];
	int count[100];

	// Initialise count of all Range
	for (int i = 0; i < 10; i++)
		count[i] = 0;

	// Count the occurance of exp place digit in number
	for (int i = 0; i < n; i++)
		count[(A[i] / exp) % 10]++;

	// Sum up the count with its previous element
	for (int i = 1; i < 10; i++)
		count[i] = count[i] + count[i - 1];

	// Place the number based on the counts
	for (int i = n - 1; i >= 0; i--)
	{
		int index = count[(A[i] / exp) % 10] - 1;
		output[index] = A[i];
		count[(A[i] / exp) % 10]--;
	}

	// Copy the output to the Array.
	for (int j = 0; j < n; j++)
		A[j] = output[j];
}

void RadixSort(int* A, int n)
{
	int max = getMax(A, n);

	for (int exp = 1; max / exp > 0; exp *= 10)
		CountSort(A, n, exp);
}

int main()
{
	int A[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int n = sizeof(A) / sizeof(A[0]);

	RadixSort(A, n);

	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);

	return 0;
}
