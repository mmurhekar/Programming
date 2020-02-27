#include <stdio.h>

void stk1_push(int *stk, int *top1, int *top2, int size, int val)
{
	if (*top1 + 1 == *top2)
	{
		printf("Stack 1 overflow\n");
		return;
	}

	if (*top1 == -1)
		*top1 = 0;

	stk[*top1] = val;
	*top1 = *top1 + 1;
}

void stk1_push(int *stk, int *top1, int *top2, int size, int val)
{
	if (*top1 == size-1 || *top2 - 1 == *top1)
	{
		printf("Stack 2 overflow\n");
		return;
	}

	if (*top2 == -1)
		*top2 = size-1;

	stk[*top2] = val;
	*top2 = *top2 + 1;
}

int stk1_pop(int *stk, int *top1, int *top2, int size)
{
	if (*top1 == -1 || *top2 == 0)
	{
		printf("Stack 1 Underflow\n");
		return -1;
	}

	int val = stk[*top1];
	*top1 = *top1 - 1;
	return val;
}

int stk2_pop(int *stk, int *top1, int *top2, int size)
{
	if (*top1 == size - 1 || *top2 == size)
	{
		*top2 = -1;
		printf("Stack 2 Underflow\n");
		return -1;
	}

	int val = stk[*top2];
	*top2 = *top2 + 1;
	return val;
}

int main ()
{
	int arr[10];
	int top1 = -1;
	int top2 = -1;
	int n = sizeof(arr)/sizeof(arr[0]);

	stk1_push(arr, &top1, &top2, n, 1);
	stk1_push(arr, &top1, &top2, n, 2);
	stk1_push(arr, &top1, &top2, n, 3);
	stk2_push(arr, &top1, &top2, n, 9);
	stk2_push(arr, &top1, &top2, n, 8);
	stk2_push(arr, &top1, &top2, n, 7);

	return 0;
}
