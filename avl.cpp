#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* right;
  Node* left;
  int height = 0;
}

struct AVL {
  Node* root;
  int size = 0;
}

Node* search(Node* root, int val) {
  if (root == nullptr) return nullptr;
  if (root->data == val) {
    return root;
  } else if (root->data < val) {
    return search(root->right, val);
  } else {
    return search(root->left, val);
  }
}

void insert(Node* root, Node* n) {
  // must balance the tree after inserting
}

void print(Node* root) {
  if (root == nullptr) {
    return;
  } else {
    cout << print(root->left) << " " << root->data << " " << print(root->right);
  }
}

int main() {
  
}
