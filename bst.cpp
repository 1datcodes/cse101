#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;

  Node(int key) {
    data = key;
    left = NULL; right = NULL;
  }
};

Node* insert(Node* root, int val) {
  if (root == NULL) {
    return new Node(val);
  }
  if (root->data == val) return root;
  if (val < root->data) {
    root->left = insert(root->left, val);
  } else {
    root->right = insert(root->right, val);
  }
  return root;
}

Node* buildBST(int a[], int n, int* idx, int lo, int hi) {
  if (*idx == n) return NULL;
  int key = a[*idx];
  if (key <= lo || key >= hi) return NULL;
  (*idx)++;
  Node* node = new Node(key);
  node->left = buildBST(a, n, idx, lo, key);
  node->right = buildBST(a, n, idx, key, hi);
  return node;
}

void print(Node* root) {
  if (root == NULL) return;
  cout << root->data << " ";
  print(root->left);
  print(root->right);
}

int main() {
  int a[8] = {40, 20, 10, 30, 50, 60, 70, 80};
  int i = 0;
  Node* b = buildBST(a, 8, &i, INT_MIN, INT_MAX);
  print(b);
}
