#include <stdio.h>

typedef struct node_t {
	int val;
	struct node_t* left, * right;
	node_t(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	};
} node_t;

node_t* FindLca(node_t* root, int key1, int key2)
{
	if (root == NULL)
		return NULL;

	if (root->val == key1 || root->val == key2)
		return root;

	node_t* leftptr = FindLca(root->left, key1, key2);
	node_t* rightptr = FindLca(root->right, key1, key2);

	if (leftptr && rightptr) return root;

	return (leftptr != NULL) ? leftptr : rightptr;
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

	node_t* lca = FindLca(root, 4, 6);
	printf("LCA = %d\n", lca->val);


	return 0;
}
#endif