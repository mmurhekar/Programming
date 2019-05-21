// Check if two given binary trees are identical
#include <stdio.h>
#include <malloc.h>

typedef struct node_t {
  int key;
  struct node_t *left, *right;
} node;

node *newNode(int key)
{
  node *Node = (node *)calloc(1, sizeof(node));
  Node->key = key;
  return Node;
}

void printInorder(node *root)
{
  if (!root)
    return;

  printInorder(root->left);
  printf("%d ", root->key);
  printInorder(root->right);
}
// Recursive Method
int IsIdentical(node *root1, node *root2)
{
  if (!root1 && !root2)
    return 1;

  return ((root1 && root2) && (root1->key == root2->key) && IsIdentical(root1->left, root2->left) && IsIdentical(root1->right, root2->right));
}

#if 1
int main()
{
  node *root, *Root;

  root = newNode(15);
  root->left = newNode(10);
  root->right = newNode(20);
  root->left->left = newNode(8);
  root->left->right = newNode(12);
  root->right->left = newNode(16);
  root->right->right = newNode(25);

  Root = newNode(15);
  Root->left = newNode(10);
  Root->right = newNode(20);
  Root->left->left = newNode(8);
  Root->left->right = newNode(12);
  Root->right->left = newNode(16);
  Root->right->right = newNode(25);

  printf("Tree 1 :- ");
  printInorder(root);
  printf("\nTree 2 :- ");
  printInorder(Root);
  printf("\n");

  if (IsIdentical(root, Root))
    printf("Both are Identical Binary Trees\n");
  else
    printf("Not Identical\n");

  return 0;
}
#endif
