#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define N 8

int dr[] = {2, 1, -1, -2, -2, -1, 1, 2, 2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1, 1};

bool IsSafe(int row, int col)
{
   if (row < 0 || row >= N || col < 0 || col >= N)
      return 0;

   return 1;
}

void KnightTour(int **visited, int row, int col, int pos)
{
   int i, j, k;

   visited[row][col] = pos;

   if (pos >= (N*N)) {
      for (i = 0; i < N; i++)
      {
         for (j = 0; j < N; j++)
            printf("%d ", visited[i][j]);
         printf("\n");
      }
      printf("\n\n");
      visited[row][col] = 0;
      return;
   }

   for (k = 0; k < 8; k++)
   {
      int newr = row + dr[k];
      int newc = col + dc[k];

      if (IsSafe(newr, newc) && !visited[newr][newc])
      {
         KnightTour(visited, newr, newc, pos+1);
      }
   }

   visited[row][col] = 0;
}

int main()
{
   int i, j;

   int **visited = (int **)calloc(N, sizeof(int*));
   for (i = 0; i < N; i++)
      visited[i] = (int *)calloc(N, sizeof(int));

   KnightTour(visited, 0, 0, 1);

   return 0;
}
