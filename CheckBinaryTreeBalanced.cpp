#include <stdio.h.>
#include <math.h>

#define max(x, y) (x > y)? x : y

typedef struct Node_t {
	int val;
	struct Node_t* left, * right;
	Node_t(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
} Node_t;

int CheckHeightBalanced(Node_t* Root, bool *balanced)
{
	if (Root == NULL)
		return 0;

	int leftSub = CheckHeightBalanced(Root->left, balanced);
	int rightSub = CheckHeightBalanced(Root->right, balanced);

	if (abs(leftSub - rightSub) > 1)
		balanced = false;

	return max(leftSub, rightSub) + 1;
}
#if 0
int main()
{
	bool isBalanced = true;
	Node_t* Root = new Node_t(1);
	Root->left = new Node_t(2);
	Root->right = new Node_t(3);
	Root->left->left = new Node_t(4);
	Root->left->right = new Node_t(5);
	Root->right->left = new Node_t(6);

	int height = CheckHeightBalanced(Root, &isBalanced);
	printf("Height = %d, Balanced = %d\n", height, isBalanced);

	return 0;
}
#endif