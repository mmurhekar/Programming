/* *
 * Use 2 stacks to store the order of child nodes
 * Alternatively.
 * */
#include <stdio.h>

typedef struct node_t {
  int key;
  struct node_t *left, *right;

  node_t(int key) {
    this->key = key;
    this->left = this->right = NULL;
  }
} node;

node *stack1[100];
node *stack2[100];

void PrintSpiral(node *root)
{
  int top1, top2;
  node *temp;
  top1 = top2 = 0;

  stack1[top1++] = root;

  while( top1 > 0 || top2 > 0) {

    while(top1 > 0) {
      temp = stack1[top1-1];
      top1--;
      printf("%d ", temp->key);

      // Push right to left
      stack2[top2++] = temp->right;
      stack2[top2++] = temp->left;
    }

    while(top2 > 0) {
      temp = stack2[top2-1];
      top2--;
      printf("%d ", temp->key);

      // Push left to right
      stack1[top1++] = temp->left;
      stack1[top1++] = temp->right;
    }
  }
}

int main (int argc, char **argv)
{
  node *root;

  root = new node(15);
  root->left = new node(10);
  root->right = new node(20);
  root->left->left = new node(8);
  root->left->right = new node(12);
  root->right->left = new node(16);
  root->right->right = new node(25);

  printf("Spiral Print :-\n");
  PrintSpiral(root);
  return 0;
}
