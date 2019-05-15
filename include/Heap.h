/*
 * Heap Operation */
#ifndef __HEAP__
#define __HEAP__

typedef struct {
	int data;
} heapNode;

typedef struct {
	int size;
	int count;
	heapNode *elem;
} heap_t;

void init_heap (int size);
void create_max_heap (int *elem, int size);
void insert_node (int data);
void delete_node(void);
void display_heap(void);

#endif /* __HEAP__ */
