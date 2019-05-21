// Reverse Level Order Traversal of the Tree
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

typedef struct Node_t {
  /* data */
  int key;
  struct Node_t *right, *left;
  Node_t(int key)
  {
    this->key = key;
    this->right = this->left = nullptr;
  }
} Node_t;

int ReverseLevelOrder( Node_t *root ) {
  /* code */
  queue<Node_t *> q;
  stack<int> s;

  q.push(root);

  while (!q.empty()) {
    Node_t *temp = q.front();
    q.pop();

    s.push(temp->key);

    if (temp->right)
      q.push(temp->right);

    if (temp->left)
      q.push(temp->left);
  }

  while (!s.empty()) {
    cout << s.top()<< " ";
    s.pop();
  }

  return 0;
}


int main(int argc, char const *argv[]) {
  /* code */

  Node_t *root;

  root = new Node_t(15);
  root->left = new Node_t(10);
  root->right = new Node_t(20);
  root->left->left = new Node_t(8);
  root->left->right = new Node_t(12);
  root->right->left = new Node_t(16);
  root->right->right = new Node_t(25);

  ReverseLevelOrder(root);

  return 0;
}
