//#include <stdio.h>
//
//#define MAX(_a, _b) (_a > _b)? _a : _b
//
//typedef struct node_t {
//	int val;
//	struct node_t* left, * right;
//	node_t(int val) { this->val = val; this->left = this->right = NULL; };
//} node_t;
//
//typedef struct Stack_t {
//
//}Stack_t;
//
//int IsBinaryTreeIdentical(node_t* root1, node_t* root2)
//{
//	if (root1 == NULL && root2 == NULL)
//		return 1;
//
//	if (root1->val != root2->val)
//		return 0;
//
//	int lret = IsBinaryTreeIdentical(root1->left, root2->left);
//
//	int rret = IsBinaryTreeIdentical(root1->right, root2->right);
//
//	return (lret && rret);
//}
//
//int HeightOfBinaryTree(node_t* root)
//{
//	if (root == NULL)
//		return 0;
//
//	int left = HeightOfBinaryTree(root->left);
//	int right = HeightOfBinaryTree(root->right);
//
//	return (MAX(left, right) + 1);
//}
//#if 0
//int main()
//{
//	node_t* Root1 = new node_t(1);
//	Root1->left = new node_t(2);
//	Root1->right = new node_t(3);
//	Root1->left->left = new node_t(4);
//	Root1->left->right = new node_t(5);
//	Root1->right->left = new node_t(6);
//	Root1->right->right = new node_t(7);
//
//	node_t* Root2 = new node_t(1);
//	Root2->left = new node_t(2);
//	Root2->right = new node_t(3);
//	Root2->left->left = new node_t(3);
//	Root2->left->right = new node_t(5);
//	Root2->right->left = new node_t(6);
//	Root2->right->right = new node_t(7);
//
//	printf("Height of Tree = %d\n", HeightOfBinaryTree(Root1));
//
//	if (IsBinaryTreeIdentical(Root1, Root2))
//		printf("Identical\n");
//	else
//		printf("not identical\n");
//
//	return 0;
//}
//#endif