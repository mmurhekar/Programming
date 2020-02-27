#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 100

// Tree Node Data Structure.
typedef struct node_t {
	int val;
	struct node_t* left, * right;
	node_t(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	};
} node_t;

typedef struct Stack_t {
	int top;
	node_t** arr;
} Stack_t;

Stack_t* CreateStack(Stack_t* st, int size)
{
	st = (Stack_t*)malloc(sizeof(Stack_t));
	if (st == NULL)
		return NULL;
	st->top = -1;
	st->arr = (node_t * *)malloc(sizeof(node_t*) * size);
	return st;
}

void Push(Stack_t* st, node_t* node)
{
	if (st->top >= MAX_SIZE)
		return;

	st->top++;
	st->arr[st->top] = node;
}

node_t* Pop(Stack_t* st)
{
	node_t* nodeptr = NULL;
	if (st->top <= -1)
		return NULL;

	nodeptr = st->arr[st->top];
	st->top--;
	return nodeptr;
}

bool IsStackEmpty(Stack_t* st)
{
	if (st->top > -1)
		return false;
	return true;
}

void PrintPreOrder(node_t* root)
{
	node_t* curr = root;
	Stack_t* stack = NULL;
	stack = CreateStack(stack, MAX_SIZE);

	while (curr != NULL || !IsStackEmpty(stack)) {

		while (curr != NULL) {
			Push(stack, curr);
			curr = curr->left;
		}

		curr = stack->arr[stack->top];
		printf("%d ", curr->val);
		Pop(stack);
		curr = curr->right;
	}
}

void PrintSpiralOrder(node_t* root)
{
	bool EvenLevel;
	Stack_t* stackEven = NULL, * stackOdd = NULL;

	stackEven = CreateStack(stackEven, MAX_SIZE);
	stackOdd = CreateStack(stackOdd, MAX_SIZE);

	if (root == NULL)
		return;

	Push(stackOdd, root);
	EvenLevel = false;

	while ((EvenLevel && !IsStackEmpty(stackEven)) || !IsStackEmpty(stackOdd)) {
		if (EvenLevel) {
			while (!IsStackEmpty(stackEven)) {
				node_t* curr = Pop(stackEven);
				printf("%d ", curr->val);

				// Push the child nodes to Odd Stack
				if (curr->right)
					Push(stackOdd, curr->right);
				if (curr->left)
					Push(stackOdd, curr->left);
			}
		}
		else {
			while (!IsStackEmpty(stackOdd)) {
				node_t* curr = Pop(stackOdd);
				printf("%d ", curr->val);

				// Push the child nodes to the Even Stack
				if (curr->left)
					Push(stackEven, curr->left);
				if (curr->right)
					Push(stackEven, curr->right);
			}
		}

		// Switch the Even level flag
		EvenLevel = !EvenLevel;
		printf("\n");
	}
}
#if 0
int main()
{
	node_t* root = new node_t(1);
	root->left = new node_t(2);
	root->right = new node_t(3);
	root->left->left = new node_t(4);
	root->left->right = new node_t(5);
	root->right->left = new node_t(6);
	root->right->right = new node_t(7);
	root->left->left->left = new node_t(8);
	root->left->left->right = new node_t(9);
	root->left->right->left = new node_t(10);
	root->left->right->right = new node_t(11);
	root->right->left->left = new node_t(12);
	root->right->left->right = new node_t(13);
	root->right->right->left = new node_t(14);
	root->right->right->right = new node_t(15);
	//PrintPreOrder(root);
	//printf("\n");
	PrintSpiralOrder(root);
	return 0;
}
#endif