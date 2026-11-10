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

Node* rotate_right(Node* z) {
  Node* y = z->left;
  Node* B = y->right;
  y->right = z;
  z->left = B;
  update(z); // update lower node first
  update(y);
  return y;
}

Node* rotate_left(Node* left) {

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
