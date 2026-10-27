#include <iostream>
using namespace std;

const int MAX = 100;

class MaxHeap {
  public:
    int a[MAX + 1];
    int n;
    MaxHeap() { n = 0; }
};

void swapAt(int i, int j) {
  int t = a[i]; a[i] = a[j]; a[j] = t;
}

// Max will always be at a[1] unless the heap is empty
int findMax() {
  if (n == 0) { cout << "Heap empty" << endl; return -1; }
  return a[i];
}

// move a[i] UP while it is larger than its parent
void swim(int i) {
  if (i == 1) return;
  if (a[i/2] > a[i]) return;
  swapAt(i, i / 2);
  swim(i / 2);
}

void sink(int i) { // member of maxHeap, a[1...n], root at a[1]
  int c = 2 * i; // left child
  if (c > n) return; // base case: no children, nothing to do
  if (c + 1 <= n && a[c + 1] > a[c]) c++; // pick the larger child
  if (a[i] >= a[c]) return; // base case: heap order already holds
  swapAt(i, c); // a[i] was smaller than its larger child
  sink(c); // continue from the child's position
}

// insert add at the end and swim up
void insert(int x) {
  if (n == MAX) { cout << "Heap full" << endl; return; }
  a[++n] = x;
}
