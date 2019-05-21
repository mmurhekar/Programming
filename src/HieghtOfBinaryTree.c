// Print height of the Binary Tree
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

int max(int , int );

int height(node *root)
{
  if (!root)
    return 0;

  //printf("%d\n", root->key);
  return (1 + max(height(root->left), height(root->right)));
}

int max(int a, int b)
{
  if (a > b)
    return a;

  return b;
}

int main()
{
  node *root = NULL;

  root = newNode(15);
  root->left = newNode(10);
  root->right = newNode(20);
  root->left->left = newNode(8);
  root->left->right = newNode(12);
  root->right->left = newNode(16);
  root->right->right = newNode(25);

  //printInorder(root);
  printf("Height of Tree:- %d\n", height(root));
  return 0;
}
