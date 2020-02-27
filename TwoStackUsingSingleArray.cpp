// Implement Two Stack given a single Array.
#include <stdio.h>

#define MAX_ARRAY_SIZE 10

int topA = -1;
int topB = -1;

void PushA(int stk[], int val)
{
		if ( topA+1 == topB || topA+1 == MAX_ARRAY_SIZE || topB == 0)
		{
			printf("Stack 1 is overflow\n");
			return;
		}

		stk[topA+1] = val;
		topA += 1;
}

void PushB(int stk[], int val)
{
		if ( topB-1 == topA || topB-1 == -1 || topA == MAX_ARRAY_SIZE-1)
		{
			printf("Stack 2 is overflow\n");
			return;
		}

		if (topB == -1)
			topB = MAX_ARRAY_SIZE;

		stk[topB-1] = val;
		topB -= 1;
}

int PopA(int stk[])
{
		if (topA == -1 || topB == 0)
		{
			printf("Stack 1 is underflow\n");
			return -1;
		}

		int val = stk[topA];
		topA -= 1;
		printf("Stack A pop: %d\n", val);
		return val;
}

int PopB(int stk[])
{
		if (topB == MAX_ARRAY_SIZE || topA == MAX_ARRAY_SIZE-1)
		{
			topB = -1;
			printf("Stack 2 is underflow\n");
			return -1;
		}

		int val = stk[topB];
		topB += 1;
		printf("Stack B pop: %d\n", val);
		return val;
}

int main()
{
	int arr[MAX_ARRAY_SIZE], i;

PushA(arr, 1);
PushA(arr, 2);
PushA(arr, 3);

PushB(arr, 9);
PushB(arr, 8);
PushB(arr, 7);

PushA(arr, 4);
PushB(arr, 6);
PushA(arr, 5);
PushB(arr, 3);

	for (i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	PushA(arr, 10);
	PushB(arr, 11);

	PopA(arr);
	PopB(arr);
	PopA(arr);
	PopB(arr);
	PopA(arr);
	PopB(arr);
	PopA(arr);
	PopB(arr);
	PopA(arr);
	PopB(arr);

	PopA(arr);
	PopB(arr);

	return 0;
}
