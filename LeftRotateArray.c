#include <stdio.h>

#include "LeftRotateArray.h"

#define MAX 10

static void leftRotateByOne(int *a, int n)
{
	int temp = a[0];
	int i;

	for (i = 0; i < n - 1; i++)
		a[i] = a[i + 1];

	a[i] = temp;
}

void LeftRotate(int *a, int num, int n)
{
	for (int i = 0; i < num; i++)
		leftRotateByOne(a, n);
}

int main ()
{
	int arry[] = {1, 2, 3, 4, 5, 6, 7};
	int N = sizeof(arry)/sizeof(arry[0]);

	printf("Array size = %d, N = %d\n", sizeof(arry), N);

	// Initail Array
	for (int i = 0; i < N; i++)
		printf("%d ", arry[i]);
	printf("\n");

	LeftRotate(arry, 2, N);

	// After Rotation
	for (int i = 0; i < N; i++)
		printf("%d ", arry[i]);
	printf("\n");

	return 0;
}
