/*
 * Link list Programs */
#include <stdio.h>
#include <malloc.h>

typedef struct listNode_t {
	int data;
	struct listNode_t *next;
} listNode;

void insert_new_node(listNode **head, int data)
{
	listNode *nodeptr = (listNode *)calloc(1, sizeof(listNode));
	nodeptr->data = data;
	nodeptr->next = *head;
	*head = nodeptr;
}

void reverseList(listNode **head)
{
	listNode *prev, *curr;

	if (*head == NULL)
		return;

	prev = NULL;
	curr = *head;

	while (curr != NULL) {
		listNode *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*head = prev;
}

void evenList(listNode **head)
{
	listNode *curr, *tail;

	if (*head == NULL)
		return;

	curr = *head;
	while (curr != NULL && curr->data % 2 != 0)
		curr = curr->next;

	if (curr == NULL)
		return;

	listNode dummy;
	dummy.next = curr;
	tail = dummy.next;
	curr = curr->next;
	while (curr != NULL) {
		if (curr->data % 2 == 0) {
			tail->next = curr;
			tail = curr;
		}
		curr = curr->next;
	}

	tail->next = NULL;
	*head = dummy.next;
}

listNode *swapNodes(listNode *head, int key1, int key2)
{
	if (head == NULL)
		return head;

	listNode *prev1, *curr1;
	prev1 = NULL;
	curr1 = head;
	while (curr1 != NULL && curr1->data != key1) {
		prev1 = curr1;
		curr1 = curr1->next;
	}

	listNode *prev2, *curr2;
	prev2 = NULL;
	curr2 = head;
	while (curr2 != NULL && curr2->data != key2) {
		prev2 = curr2;
		curr2 = curr2->next;
	}

	if (curr1 == NULL || curr2 == NULL)
		return head;

	if (prev1 == NULL) {
		head = curr2;
	} else {
		prev1->next = curr2;
	}

	if (prev2 == NULL) {
		head = curr1;
	} else {
		prev2->next = curr1;
	}

	// swap next pointers of both nodes
	listNode *tmp;
	tmp = curr1->next;
	curr1->next = curr2->next;
	curr2->next = tmp;

	return head;
}

listNode *reverseKNodes(listNode *head, int k)
{
	listNode *prev, *curr, *next;
	int count = 0;

	if (head == NULL)
		return head;

	prev = NULL;
	next = NULL;
	curr = head;
	while (curr != NULL && count < k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	if (next)
		head->next = reverseKNodes(next, k);

	return prev;
}

/*
 * Remove Duplicate nodes from Sorted Linklist
 * */
void removeDuplicate1(listNode **head)
{
	listNode *curr = *head;
	listNode *next = NULL;

	if (curr == NULL)
		return;

	while (curr->next != NULL) {
		if (curr->data == curr->next->data) {
			next = curr->next->next;
			free(curr->next);
			curr->next = next;
		} else
			curr = curr->next;
	}
}

/*
 * Remove Duplicate nodes from Unsorted Linklist
 * */
void removeDuplicate2(listNode **head)
{
	listNode *curr = *head;

	if (curr == NULL)
		return;

	while (curr != NULL) {
		listNode *runner = curr;
		while (runner->next != NULL) {
			if (runner->next->data == curr->data) {
				listNode *next = runner->next->next;
				free(runner->next);
				runner->next = next;
			}
		}
		curr = curr->next;
	}
}

void printList(listNode *head)
{
	listNode *curr = head;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

int main ()
{
	listNode *head = NULL;
#if 1
	insert_new_node(&head, 3);
	insert_new_node(&head, 13);
	insert_new_node(&head, 3);
	insert_new_node(&head, 15);
	insert_new_node(&head, 20);
	insert_new_node(&head, 11);
	insert_new_node(&head, 13);
	insert_new_node(&head, 11);
	insert_new_node(&head, 15);
	insert_new_node(&head, 20);
	insert_new_node(&head, 11);
#else
	insert_new_node(&head, 11);
	insert_new_node(&head, 11);
	insert_new_node(&head, 11);
	insert_new_node(&head, 15);
	insert_new_node(&head, 15);
	insert_new_node(&head, 20);
	insert_new_node(&head, 20);
	insert_new_node(&head, 20);
	insert_new_node(&head, 21);
	insert_new_node(&head, 22);
	insert_new_node(&head, 22);
#endif
//	printf("before: ");
//	printList(head);

//	head = swapNodes(head, 1, 13);

//	printf("after: ");
//	printList(head);

//	reverseList(&head);

//	printf("after: ");
//	printList(head);

//	evenList(&head);
//	printf("after: ");
//	printList(head);

	printf("before R: ");
	printList(head);

//	head = reverseKNodes(head, 3);
//	removeDuplicate1(&head);
	removeDuplicate2(&head);

	printf("after R: ");
	printList(head);

	return 0;
}
