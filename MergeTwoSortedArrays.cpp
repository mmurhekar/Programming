// Merge two Sorted Arrays into first Array without an auxilary Array.

#include <stdio.h>

void MergeSortedArrays(int* A, int* B, int Alen, int Blen, int Asize, int Bsize)
{
	int Aindex, Bindex, Mindex;

	Aindex = Alen - 1;
	Bindex = Blen - 1;
	Mindex = Asize - 1;

	// If no space found to accomodate
	if (Alen + Blen > Asize)
		return;

	while (Aindex >= 0 && Bindex >= 0)
	{
		if (A[Aindex] > B[Bindex])
		{
			A[Mindex] = A[Aindex];
			Aindex--;
		}
		else
		{
			A[Mindex] = B[Bindex];
			Bindex--;
		}

		Mindex--;
	}

	while (Aindex >= 0)
	{
		A[Mindex] = A[Aindex];
		Aindex--;
		Mindex--;
	}
}


int main()
{
	int A[] = { 1, 3, 5, 0, 0, 0, 0, 0 };
	int B[] = { 2, 4, 6, 8, 10 };

	MergeSortedArrays(A, B, 3, 5, 8, 5);

	for (int i = 0; i < 8; i++)
		printf("%d ", A[i]);
	printf("\n");


	return 0;
}
