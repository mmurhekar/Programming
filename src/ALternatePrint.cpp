// Alternate Print from Top to bottom in a perfect binary tree
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

void PrintInOrder(Node_t *root)
{
  if (root == nullptr)
    return;

  std::cout << root->key << " ";
  PrintInOrder(root->left);
  PrintInOrder(root->right);
}

// Print the nodes in To-Down fashion
void PrintAlternateUtil(Node_t *root)
{
  if (root == nullptr)
    return;

  queue<Node_t *> Q1, Q2;
  cout<<root->key<<" ";

  if (root->left)
    Q1.push(root->left);
  if (root->right)
    Q2.push(root->right);

  // While Queue is not empty
  while (!Q1.empty())
  {
    Node_t *temp = Q1.front();
    Q1.pop();

    // Print the left sub tree child Node_t
    // and push into the first queue
    cout<<temp->key<<" ";
    if (temp->left)
      Q1.push(temp->left);

    if (temp->right)
      Q1.push(temp->right);

    temp = Q2.front();
    Q2.pop();

    // Print the right sub tree child Node_t
    // and push into the second queue
    cout<<temp->key<<" ";
    if (temp->right)
      Q2.push(temp->right);

    if (temp->left)
      Q2.push(temp->left);
  }
}

int main(int argc, char const *argv[]) {
  /* code */

  Node_t *root;

  root = new Node_t(1);
  root->left = new Node_t(2);
  root->right = new Node_t(3);
  root->left->left = new Node_t(4);
  root->left->right = new Node_t(5);
  root->right->left = new Node_t(6);
  root->right->right = new Node_t(7);

  root->left->left->left = new Node_t(8);
  root->left->left->right = new Node_t(9);
  root->left->right->left = new Node_t(10);
  root->left->right->right = new Node_t(11);

  root->right->left->left = new Node_t(12);
  root->right->left->right = new Node_t(13);

  root->right->right->left = new Node_t(14);
  root->right->right->right = new Node_t(15);

  PrintInOrder(root);

  cout<<"Alternate Print Top Down"<<endl;
  PrintAlternateUtil(root);

  return 0;
}
