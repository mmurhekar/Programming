#include <stdio.h>

typedef struct node_t {
	int val;
	struct node_t* next;
	node_t(int val)
	{
		this->val = val;
		this->next = NULL;
	};
} node_t;

node_t* _Reverse_(node_t* head)
{
	node_t* prev, * curr;
	curr = head;
	prev = NULL;

	while (curr != NULL) {
		node_t* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

void ReverseList(node_t** list, int pos1, int pos2)
{
	node_t* curr1, * prev;
	node_t* curr2, * next;
	int count;
	
	if (*list == NULL)
		return;
	if (pos1 == pos2)
		return;

	if (pos1 > pos2) {
		int temp = pos1;
		pos1 = pos2;
		pos2 = pos1;
	}

	curr1 = *list;
	prev = NULL;
	count = 1;
	while (curr1 != NULL && count < pos1) {
		count++;
		prev = curr1;
		curr1 = curr1->next;
	}

	curr2 = NULL;
	next = (*list)->next;
	count = 1;
	while (next != NULL && count < pos2) {
		count++;
		curr2 = next;
		next = next->next;
	}

	if (curr1 == NULL || curr2 == NULL)
		return;

	node_t* start = curr1;
	node_t* end   = curr2;
	curr2->next = NULL;
	if (prev)
		prev->next = curr2;
	else
		*list = curr2;

	curr1 = _Reverse_(curr1);
	start->next = next;
}

#if 0
int main()
{
	node_t* list = new node_t(1);
	list->next = new node_t(2);
	list->next->next = new node_t(3);
	list->next->next->next = new node_t(4);
	list->next->next->next->next = new node_t(5);
	list->next->next->next->next->next = new node_t(6);

	ReverseList(&list, 5, 6);

	for (node_t* l = list; l != NULL; l = l->next) {
		printf("%d -> ", l->val);
	}

	return 0;
}
#endif
