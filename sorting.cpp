#include <iostream>

void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int min = arr[i];
    int min_index = i;
    for (int j = i; j < n; j++) {
      if (arr[j] < min) {
        min = arr[j], min_index = j;
      }
    }
    swap(arr, i, min_index);
  }
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1);
      }
    }
  }
}

void insertionSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      swap(arr, j, j - 1);
      j--;
    }
  }
}

void print(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void search(int arr[], int n, int val) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == val) {
      return i;
    }
  }
  return -1;
}

/*
 * Selection Sort Analysis:
 * Outer loop (int i) runs from 0 to n
 * Inner loop (int j) runs from i to n
 * Total inside runs n(n+1)/2 or O(n^2)
 *
 * Insertion Sort Analysis:
 * Outer loop (int i) from 0 to n
 * Inner loop (int j) runs i times
 * Total inside runs in O(n^2)
*/

int main() {
  int a[] = {5, 3, 9, 4, 20};
  print(a, 5);
  selectionSort(a, 5); 
  print(a, 5);

  int b[] = {5, 3, 2, 7, 20};
  print(b, 5);
  bubbleSort(b, 5);
  print(b, 5);

  int c[] = {5, 3, 2, 7, 10};
  print(c, 5);
  insertionSort(c, 5);
  print(c, 5);
}
