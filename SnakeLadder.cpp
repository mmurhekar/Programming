// Snake and Ladder Problem using BFS Algo.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct node_t {
	int v;
	int dist;
} node_t;

int getMinDist(int move[], int n)
{
	queue<node_t> q;

	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	// Visited source vertex
	visited[0] = true;
	node_t s = { 0, 0 };
	q.push(s);
	
	node_t node;
	while (!q.empty()) {

		node = q.front();
		q.pop();
		int v = node.v;

		if (v == n - 1)
			break;

		for (int j = v + 1; j <= v + 6 && j < n; j++)
		{
			if (!visited[j]) {
				
				node_t que;
				que.dist = node.dist + 1;
				visited[j] = true;

				if (move[j] != -1) {
					que.v = move[j];
				}
				else {
					que.v = j;
				}

				q.push(que);
			}
		}
	}

	return node.dist;
}

int main()
{
	// Let us construct the board given in above diagram 
	int N = 30;
	int moves[30];
	for (int i = 0; i < N; i++)
		moves[i] = -1;

	// Ladders 
	moves[2] = 21;
	moves[4] = 7;
	moves[10] = 25;
	moves[19] = 28;

	// Snakes 
	moves[26] = 0;
	moves[20] = 8;
	moves[16] = 3;
	moves[18] = 6;

	cout << "Min Dice throws required is " << getMinDist(moves, N);
	return 0;
}