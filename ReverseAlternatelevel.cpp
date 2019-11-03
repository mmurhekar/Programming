// Reverse alternate levels of a perfect binary tree
#include <stdio.h>

struct Node {
  char key;
  struct Node *left, *right;
  Node(int key) {
    this->key = key;
    this->left = this->right = NULL;
  }
};

void PrintInOrder(struct Node *root)
{
  if (root == NULL)
    return;

  PrintInOrder(root->left);
  printf("%c ", root->key);
  PrintInOrder(root->right);
}

void swap(char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

void ReverseAltLevelUtil(Node *r1, Node *r2, int level)
{
  if (r1 == NULL || r2 == NULL)
    return;

  if (level%2 == 0)
    swap(&(r1->key), &(r2->key));

  ReverseAltLevelUtil(r1->left, r2->right, level+1);
  ReverseAltLevelUtil(r1->right, r2->left, level+1);
}

void ReverseAltLevel(Node *root)
{
  if (root == NULL)
    return;

  ReverseAltLevelUtil(root->left, root->right, 0);
}

int main(int argc, char const *argv[]) {

  struct Node *root = new Node('a');
  root->left = new Node('b');
  root->right = new Node('c');
  root->left->left = new Node('d');
  root->left->right = new Node('e');
  root->right->left = new Node('f');
  root->right->right = new Node('g');
  root->left->left->left = new Node('h');
  root->left->left->right = new Node('i');
  root->left->right->left = new Node('j');
  root->left->right->right = new Node('k');
  root->right->left->left = new Node('l');
  root->right->left->right = new Node('m');
  root->right->right->left = new Node('n');
  root->right->right->right = new Node('o');

  printf("Before InOrder :- ");
  PrintInOrder(root);
  printf("\n");

  ReverseAltLevel(root);

  printf("After InOrder :- ");
  PrintInOrder(root);
  printf("\n");


  return 0;
}
