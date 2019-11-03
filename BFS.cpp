#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdint.h>

typedef struct node {
	int dest;
	struct node* next;
} node;

node *vert[100];
int edgecount[100];
int visited[100];
int queue[100];

void add_edge(node** vrt, int src, int dest)
{
	node* n1, * curr;
	n1 = (node*)malloc(sizeof(node));
	if (n1 == NULL)
		return;

	n1->next = NULL;
	n1->dest = dest;

	edgecount[src]++;

	if (vrt[src] == NULL) {
		vrt[src] = n1;
		return;
	}

	curr = vrt[src];
	while (curr->next != NULL)
		curr = curr->next;

	curr->next = n1;
}

void bfs(node **vrt, int src)
{
	int front, rear, x;
	front = rear = 0;
	visited[src] = 1;
	queue[rear] = src;
	rear++;

	while (front < rear)
	{
		node* curr;
		int count = 0;
		x = queue[front];
		front++;

		printf("%d ", x);

		curr = vrt[x];
		while (curr) {
			if (visited[curr->dest] == 0) {
				visited[curr->dest] = 1;
				queue[rear] = curr->dest;
				rear++;
			}
			curr = curr->next;
		}
	}
}

void dfs(node** vrt, int src)
{
	node* curr;

	visited[src] = 1;
	printf("%d ", src);

	curr = vrt[src];
	while (curr != NULL) {
		if (visited[curr->dest] == 0)
			dfs(vrt, curr->dest);
		curr = curr->next;
	}
}

int main()
{
	int i;
	add_edge(vert, 1, 2);
	add_edge(vert, 1, 3);
	add_edge(vert, 1, 4);
	add_edge(vert, 2, 5);
	add_edge(vert, 2, 6);
	add_edge(vert, 5, 9);
	add_edge(vert, 5, 10);
	add_edge(vert, 4, 7);
	add_edge(vert, 4, 8);
	add_edge(vert, 7, 11);
	add_edge(vert, 7, 12);

	//for (i = 0; i < 15; i++)
	//{
	//	if (visited[i] == 0)
	//		bfs(vert, i);
	//}

	for (i = 0; i < 15; i++)
	{
		if (visited[i] == 0)
			dfs(vert, i);
	}

	return 0;
}
