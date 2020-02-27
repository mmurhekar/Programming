#include <stdio.h>

#define N 8

bool IsSafe(char arr[][N], int r, int c)
{
	int i, j;

	// Check vertically |
	for (i = 0; i < r; i++)
	{
		if (arr[i][c] == 'Q')
			return false;
	}

	// Check diagonally \ 
	for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
	{
		if (arr[i][j] == 'Q')
			return false;
	}

	// Check diagonally / 
	for (i = r, j = c; i >= 0 && j < N; i--, j++)
	{
		if (arr[i][j] == 'Q')
			return false;
	}
	return true;
}

void SolveNQueenProblem(char arr[][N], int row, int count)
{
	int i, j;
	if (row == N)
	{
		// Print the solution
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				printf("%c ", arr[i][j]);
			}
			printf("\n");
		}

		printf("Possible count = %d\n", count);
		return;
	}

	for (int c = 0; c < N; c++)
	{
		if (IsSafe(arr, row, c) == true)
		{
			arr[row][c] = 'Q';
			SolveNQueenProblem(arr, row + 1, count + 1);
			arr[row][c] = '-';
		}
	}

	return;
}

#if 0
int main()
{
	char arr[N][N], i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			arr[i][j] = '-';
		}
	}

	SolveNQueenProblem(arr, 0, 0);

	return 0;
}
#endif