/*
 * AVL Tree Operation */
#ifndef __AVLTREE__
#define __AVLTREE__

typedef struct AVLNode_t {
	int data;
	struct AVLNode_t *left;
	struct AVLNode_t *right;
	int height;
} AVLNode;

AVLNode *insert_into_avl_tree(AVLNode *node, int key);
void PrintInOrder(AVLNode *node);

#endif /* AVLTREE */
