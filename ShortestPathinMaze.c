#include <stdio.h>
#include <malloc.h>

#define M 10
#define N 10
#define MIN(a, b) (a<b)?a:b

int isSafe(int row, int col)
{
   if (row < 0 || row >= M || col < 0 || col >= N)
      return 0;

   return 1;
}

void ShortestPath(int grid[][10], int **visited, int row, int col, int Row, int Col, int dist, int *min)
{
   int i, j;
   if (row == Row &&
         col == Col)
   {
      *min = MIN(dist, *min);
      for (i = 0; i < 10; i++)
      {
         for (j = 0; j < 10; j++)
            printf("%d ", visited[i][j]);
         printf("\n");
      }
      printf("--------------------------------\n");
      return;
   }

   visited[row][col] = 1;

   // Move Right
   if (isSafe(row, col+1) && grid[row][col+1] == 1 && !visited[row][col+1])
   {
      /* visited[row][col+1] = 1; */
      ShortestPath(grid, visited, row, col+1, Row, Col, dist+1, min);
      /* visited[row][col+1] = 0; */
   }
   // Move Left
   if (isSafe(row, col-1) && grid[row][col-1] == 1 && !visited[row][col-1])
   {
      /* visited[row][col-1] = 1; */
      ShortestPath(grid, visited, row, col-1, Row, Col, dist+1, min);
      /* visited[row][col-1] = 0; */
   }
   // Move Up
   if (isSafe(row-1, col) && grid[row-1][col] == 1 && !visited[row-1][col])
   {
      /* visited[row-1][col] = 1; */
      ShortestPath(grid, visited, row-1, col, Row, Col, dist+1, min);
      /* visited[row-1][col] = 0; */
   }
   // Move Down
   if (isSafe(row+1, col) && grid[row+1][col] == 1 && !visited[row+1][col])
   {
      /* visited[row+1][col] = 1; */
      ShortestPath(grid, visited, row+1, col, Row, Col, dist+1, min);
      /* visited[row+1][col] = 0; */
   }

   visited[row][col] = 0;
}

int main()
{
   int i,j;
   int grid[10][10] = {
      {1, 1, 1, 1, 1, 0, 0, 0, 1, 1},
      {0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
      {0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
      {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
      {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
      {1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
      {0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
      {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
      {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
      {0, 0, 1, 0, 0, 1, 1, 0, 0, 1},
   };

   int mat[M][N] = 
   {
      { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
      { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
      { 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
      { 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
      { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
      { 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
      { 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
      { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
      { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
      { 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
   };

   int min_dist = 999999;

   int **visited = (int**)malloc(sizeof(int *) * M);
   for (i = 0; i < M; i++)
      visited[i] = (int *)malloc(sizeof(int) * N);

   for (i = 0; i < M; i++)
   {
      for(j = 0; j < N; j++)
         visited[i][j] = 0;
   }

   ShortestPath(mat, visited, 0, 0, 7, 5, 0, &min_dist);
   printf("Shortest Path = %d\n", min_dist);

   return 0;
}
