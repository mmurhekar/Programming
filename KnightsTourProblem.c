// Knight Tour Problem.
// Given a source and destination on a chess board.
// find the shortes path to reach the destination from a given source.

#include <stdio.h>
#define MAX_QSIZE 100000
//#define N 8
#define N 5

typedef struct Queue_t {
	int dist;
	int row;
	int col;
} Queue_t;

Queue_t queue[MAX_QSIZE];
int front, rear;
int dr[] = {2, 1, -1, -2, -2, -1, 1, 2, 2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1, 1};
int visited[N][N];

int IsSafe(int r, int c)
{
	if (r < 0 || r >= N || c < 0 || c >= N)
		return 0;
	return 1;
}

int bfs(int sr, int sc, int fr, int fc)
{
	int r, c, dist, i;
	int nr, nc;
	front = rear = 0;

	visited[sr][sc] = 1;
	queue[rear].row = sr;
	queue[rear].col = sc;
	queue[rear].dist = 0;

	while (front <= rear)
	{
		r = queue[front].row;
		c = queue[front].col;
		dist = queue[front].dist;
		front++;

		if (r == fr && c == fc)
			return dist;

		for (i = 0; i < 8; i++)
		{
			nr = dr[i] + r;
			nc = dc[i] + c;
			if (IsSafe(nr, nc) && visited[nr][nc] == 0)
			{
				visited[nr][nc] = 1;
				rear++;
				queue[rear].row = nr;
				queue[rear].col = nc;
				queue[rear].dist = dist + 1;
			}
		}
	}

	return 0;
}

void KnightTourProblem(int row, int col, int move, int visit[][8])
{
	int k, nr, nc;

	visit[row][col] = move;

	if (move >= (N*N))
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				printf("%d ", visit[i][j]);
			printf("\n");
		}
		printf("\n\n");
		visited[row][col] = 0;
		return;
	}

	for (k = 0; k < 8; k++)
	{
		nr = row + dr[k];
		nc = col + dc[k];

		if (IsSafe(nr, nc) && !visit[nr][nc])
			KnightTourProblem(nr, nc, move + 1, visit);
	}

	visited[row][col] = 0;
}

int main()
{
	// int Ans = bfs(0, 7, 7, 0);
	// printf("Ans = %d\n", Ans);
	KnightTourProblem(0, 0, 1, visited);
	return 0;
}