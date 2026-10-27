#include <iostream>
using namespace std;

int binarySearch(int a[], int lo, int hi, int key) {
  if (lo > hi) return -1;
  int mid = (lo + hi) / 2;
  if (a[mid] == key) return mid;
  if (a[mid] < key) {
    return binarySearch(a, mid + 1, hi, key);
  } else {
    return binarySearch(a, lo, mid - 1, key);
  }
}

void print(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  int a[5] = {1, 2, 3, 4, 5};
  print(a, 5);
  int i = binarySearch(a, 0, 5, 2);
  cout << i << endl;
}
