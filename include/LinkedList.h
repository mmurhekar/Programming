/*
 * Linked List Header File*/
#ifndef __LINKEDLIST__
#define __LINKEDLIST__

typedef struct listNode_t {
	int data;
	struct listNode_t *next;
} listNode;

void insert_new_node(listNode **head, int data);
void reverseList(listNode **head);
void evenList(listNode **head);
listNode *swapNodes(listNode *head, int key1, int key2);
listNode *reverseKNodes(listNode *head, int k);
void removeDuplicate1(listNode **head);
void removeDuplicate2(listNode **head);
void printList(listNode *head);

#endif /* LINKEDLIST */
