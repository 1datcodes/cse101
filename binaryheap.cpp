#include <iostream>
using namespace std;

const int MAX = 100;

class MaxHeap {
  public:
    int a[MAX + 1];
    int n;
    MaxHeap() { n = 0; }

    void swapAt(int i, int j) {
      int t = a[i]; a[i] = a[j]; a[j] = t;
    }

    // Max will always be at a[1] unless the heap is empty
    int findMax() {
      if (n == 0) { cout << "Heap empty" << endl; return -1; }
      return a[1];
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
    // O(log n)
    void insert(int x) {
      if (n == MAX) { cout << "Heap full" << endl; return; }
      a[++n] = x; // 1. place at the next free slot (shape). ++n advances the size
      swim(n); // 2. repair the order
    }

    void print() {
      if (n <= 1) { cout << "Heap empty\n"; return; } 
      for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
      }
      cout << endl;
    }
    
    int extractMax() {
      if (n == 0) { cout << "Heap empty\n"; return -1; }
      int mx = a[1]; // the max element
      a[1] = a[n--]; // 1. last element fills the root (shape). n-- shrinks the size
      sink(1); // 2. repair the order
      return mx; // return the max element
    }
};

int main() {
  MaxHeap* h = new MaxHeap();
  h->insert(80);
  h->insert(70);
  h->insert(60);
  h->insert(30);
  h->insert(40);
  h->insert(20);
  h->insert(50);
  h->print();
  h->insert(75);
  h->print();
  cout << h->extractMax() << endl;
  h->print();
}
