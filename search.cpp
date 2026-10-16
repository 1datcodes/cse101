#include <iostream>

int search(int arr[], int n, int val) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == val) return i;
  }
  return -1;
}

int binarySearch(int arr[], int val, int lo, int hi) {
  if (lo > hi) return -1;
  int mid = lo + (hi - lo) / 2;
  if (arr[mid] == val) {
    return mid;
  }
  if (arr[mid] < val) {
    return binarySearch(arr, val, mid + 1, hi);
  } else {
    return binarySearch(arr, val, lo, mid - 1);
  }
}

void print(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

/*
 * Search:
 * worst case search takes n times --> O(n)
 *
 * Binary Search:
 * divides by 2 every recursive call --> O(log_2 n)
 */ 

int main() {
  int a[] = {1, 5, 8, 10, 29, 31};
  print(a, 6);
  std::cout << binarySearch(a, 8, 0, 6) << std::endl;
  std::cout << binarySearch(a, 9, 0, 6) << std::endl;
}
