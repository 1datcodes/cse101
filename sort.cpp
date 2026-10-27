#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
  for (int i = 0; i < n; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[minIndex]) {
        minIndex = j;
      }
    }
    int temp = a[i];
    a[i] = a[minIndex];
    a[minIndex] = temp;
  }
}

void insertionSort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && key < a[j]) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

void print(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  int a[5] = {5,3,9,1,0};
  print(a, 5);
  selectionSort(a, 5);
  print(a, 5);

  int b[5] = {5,3,9,1,0};
  insertionSort(b, 5);
  print(b, 5);
}
