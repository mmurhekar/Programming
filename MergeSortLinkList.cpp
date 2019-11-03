// Merge Sort on Given Linklist.
#include <stdio.h>

typedef struct node_t {
	int val;
	struct node_t* next;
	node_t(int val)
	{
		this->val = val;
		this->next = NULL;
	}
} node_t;

// Split the linklist into two halfs
void SplitList(node_t **head_t, node_t **low, node_t **high)
{
	node_t* head = *head_t;
	node_t* slow = head;
	node_t* fast = head->next;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	*low = head;
	*high = slow->next;
	slow->next = NULL;
}

// Merge the two half lists
node_t* Merge(node_t* low, node_t* high)
{
	node_t* a, * b;
	node_t* curr;
	node_t new_head(-1);

	a = low;
	b = high;
	curr = &new_head;

	while (a && b)
	{
		if (a->val <= b->val)
		{
			node_t* tmp = a->next;
			a->next = NULL;
			curr->next = a;
			curr = a;
			a = tmp;
		}
		else
		{
			node_t* tmp = b->next;
			b->next = NULL;
			curr->next = b;
			curr = b;
			b = tmp;
		}
	}

	if (a)
	{
		curr->next = a;
	}
	
	if (b)
	{
		curr->next = b;
	}
	
	return new_head.next;
}

void MergeSort(node_t** head_t)
{
	node_t* head = *head_t;

	node_t* low;
	node_t* high;

	if (head == NULL || head->next == NULL)
		return;

	SplitList(&head, &low, &high);
	MergeSort(&low);
	MergeSort(&high);
	*head_t = Merge(low, high);
}

int main()
{
	node_t* node = new node_t(10);

	node->next = new node_t(2);
	node->next->next = new node_t(5);
	node->next->next->next = new node_t(1);
	node->next->next->next->next = new node_t(0);
	node->next->next->next->next->next = new node_t(8);
	node->next->next->next->next->next->next = new node_t(3);
	node->next->next->next->next->next->next->next = new node_t(9);
	node->next->next->next->next->next->next->next->next = new node_t(7);

	for (node_t* list = node; list; list = list->next)
	{
		printf("%d ", list->val);
	}

	MergeSort(&node);

	printf("\n");
	for (node_t* list = node; list; list = list->next)
	{
		printf("%d ", list->val);
	}

	return 0;
}
