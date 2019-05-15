/* AVL Tree
 * Self Balancing Binary Search Tree */
#include <stdio.h>
#include <malloc.h>

#include "AVL_Tree.h"

#define max(a,b) (a>b)?a:b

static int height(AVLNode *nodeptr) {
	if (nodeptr)
		return nodeptr->height;
	return 0;
}

static AVLNode *get_new_node(int data)
{
	AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

static int balanceFactor(AVLNode *node) {
	return (height(node->left) - height(node->right));
}

/* Right Rotation */
static AVLNode *RotateRight(AVLNode *y)
{
	AVLNode *x = y->left;
	AVLNode *T2 = x->right;

	/* Rotate Right */
	x->right = y;
	y->left = T2;

	/* Update the height of x & y */
	x->height = max(height(x->left), height(x->right));
	y->height = max(height(y->left), height(y->right));
	return x;
}

/* Left Rotation */
static AVLNode *RotateLeft(AVLNode *y)
{
	AVLNode *x = y->right;
	AVLNode *T2 = x->left;

	/* Rotate Left */
	x->left = y;
	y->right = T2;

	/* Update the height of x & y */
	x->height = max(height(x->left), height(x->right));
	y->height = max(height(y->left), height(y->right));
	return x;
}

AVLNode *insert_into_avl_tree(AVLNode *node, int key)
{
	int balance;

	if (node == NULL)
		return get_new_node(key);

	/* 1. insert data normally into BST */
	if (node->data > key)
		node->left = insert_into_avl_tree(node->left, key);
	else if (node->data < key)
		node->right = insert_into_avl_tree(node->right, key);
	else
		return node;

	/* 2. update the height of all ancestors
	 *		node of newly added node */
	node->height = max(height(node->left), height(node->right)) + 1;

	/* 3. Check the Balancing factor of the node */
	balance = balanceFactor(node);

	/* Balance the node if unbalanced */

	/* a. Left Left Case:- */
	if (balance > 1 && key < node->left->data) {
		return RotateRight(node);
	}

	/* b. Right Right Case:- */
	if (balance < -1 && key > node->right->data) {
		return RotateLeft(node);
	}

	/* c. Left Right Case:- */
	if (balance > 1 && key > node->left->data) {
		node->left = RotateLeft(node->left);
		return RotateRight(node);
	}

	/* d. Right Left Case:- */
	if (balance < -1 && key < node->right->data) {
		node->right = RotateRight(node->right);
		return RotateLeft(node);
	}

	/* If already balanced do nothing */
	return node;
}

void PrintInOrder(AVLNode *node)
{
	if (node == NULL)
		return;

	PrintInOrder(node->left);
	printf("%d ", node->data);
	PrintInOrder(node->right);
}

#if 0
int main()
{
	AVLNode *root = NULL;

	root = insert_into_avl_tree(root, 10);
	printf("\n");
	PrintInOrder(root);
	printf("\n");
	root = insert_into_avl_tree(root, 5);
	printf("\n");
	PrintInOrder(root);
	printf("\n");
	root = insert_into_avl_tree(root, 4);
	printf("\n");
	PrintInOrder(root);
	printf("\n");

	root = insert_into_avl_tree(root, 3);
	printf("\n");
	PrintInOrder(root);
	printf("\n");

	root = insert_into_avl_tree(root, 20);
	printf("\n");
	PrintInOrder(root);
	printf("\n");

	root = insert_into_avl_tree(root, 1);
	printf("\n");
	PrintInOrder(root);
	printf("\n");

	root = insert_into_avl_tree(root, 2);
	printf("\n");
	PrintInOrder(root);
	printf("\n");

	root = insert_into_avl_tree(root, 15);
	printf("\n");
	PrintInOrder(root);
	printf("\n");

	root = insert_into_avl_tree(root, 21);
	root = insert_into_avl_tree(root, 14);
	root = insert_into_avl_tree(root, 16);
	root = insert_into_avl_tree(root, 13);
	root = insert_into_avl_tree(root, 12);
	root = insert_into_avl_tree(root, 11);
	root = insert_into_avl_tree(root, 6);

	printf("\n");
	PrintInOrder(root);
	printf("\n");
	return 0;
}
#endif
