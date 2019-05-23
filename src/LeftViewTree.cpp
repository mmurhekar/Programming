// Print the Left view of a binary tree
// Both Recursive and Iterative Methods
#include <stdio.h>
#include <queue>

using namespace std;

struct Node {
  int key;
  struct Node *left, *right;
  Node(int key)
  {
    this->key = key;
    this->left = this->right = 0;
  }
};

void LeftView(struct Node *root)
{
  queue<struct Node*> q;

  if (root == NULL)
    return;

  q.push(root);

  while(!q.empty()) {
    int size = q.size();
    int i = 0;
    while (i++ < size) {
      struct Node *temp = q.front();
      q.pop();

      if ( i == 1 ) {
        printf("%d ", temp->key);
      }

      if (temp->left)
        q.push(temp->left);

      if (temp->right) {
        q.push(temp->right);
      }
    } // while
  } // while
}

int arr[100];

void LeftView_Recursive(struct Node *root, int level)
{
  if (root == NULL)
    return;

  if (arr[level] == 0) {
    arr[level] = 1;
    printf("%d ", root->key);
  }

  LeftView_Recursive(root->left, level+1);
  LeftView_Recursive(root->right, level+1);
}

int main(int argc, char const *argv[]) {
  /* code */
  struct Node *root = NULL;

  root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(4);
  root->right->left = new Node(5);
  root->right->right = new Node(6);
  root->right->left->left = new Node(7);
  root->right->left->right = new Node(8);

  printf("Iterative :- ");
  LeftView(root);
  printf("\nRecursive :- ");
  LeftView_Recursive(root, 0);
  return 0;
}
