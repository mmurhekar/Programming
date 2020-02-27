#include <stdio.h>
#include <malloc.h>
#if 0
typedef struct node_t {
	int val;
	struct node_t* next;
	node_t(int val) { this->val = val; this->next = NULL; };
} node_t;

void InsertAtLast(node_t** last, int val)
{
	node_t* newnode = new node_t(val);

	// Empty list
	if (*last == NULL) {
		newnode->next = newnode;
		*last = newnode;
		return;
	}

	// Insert the node at the end of the list
	newnode->next = (*last)->next;
	(*last)->next = newnode;
	// Modify the last pointer
	*last = newnode;
}

void InsertAtbegin(node_t** last, int val)
{
	node_t* newnode = new node_t(val);

	// Empty list
	if (*last == NULL) {
		newnode->next = newnode;
		*last = newnode;
		return;
	}

	newnode->next = (*last)->next;
	(*last)->next = newnode;
}

void Print(node_t* last)
{
	node_t* curr;

	if (!last)
		return;

	curr = last->next;

	do {
		printf(" -> %d", curr->val);
		curr = curr->next;
	} while (curr != last->next);
	printf("\n");
}

int main()
{
	node_t* last = NULL;

	InsertAtLast(&last, 1);
	InsertAtLast(&last, 2);
	InsertAtLast(&last, 3);
	InsertAtLast(&last, 4);
	InsertAtLast(&last, 5);
	InsertAtLast(&last, 6);
	InsertAtLast(&last, 7);
	InsertAtbegin(&last, 10);
	InsertAtLast(&last, 11);
	Print(last);

	return 0;
}
#endif