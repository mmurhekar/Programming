// Print Top view of a binary tree.

#include <iostream>
#include <stdio.h>

#define MID 100

typedef struct Node {
	int key;
	struct Node* left, * right;
	Node(int key)
	{
		this->key = key;
		this->left = this->right = NULL;
	}
} Node;

typedef struct Queue {
	Node* node;
	int dist;
} Queue;

Queue q[100000];
Node* map[100000];

void topView(Node* root)
{
	int front, rear;

	front = rear = 0;

	q[rear].node = root;
	q[rear].dist = 0;
	rear++;

	while (front < rear) {

		Node* tmp = q[front].node;
		int dist = q[front].dist;
		front++;

		if (map[MID + dist] == NULL) {
			//printf("%d ", tmp->key);
			//map[MID + dist] = tmp;
		}

		if (tmp->left) {
			q[rear].node = tmp->left;
			q[rear].dist = dist - 1;
			rear++;
		}

		if (tmp->right) {
			q[rear].node = tmp->right;
			q[rear].dist = dist + 1;
			rear++;
		}
	}
}

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->right = new Node(4);
	root->left->right->right = new Node(5);
	root->left->right->right->right = new Node(6);

	printf("Top View:\n");
	topView(root);
	return 0;
}
