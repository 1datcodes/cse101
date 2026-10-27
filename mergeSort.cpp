#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
      data = val;
      prev = NULL;
      next = NULL;
    }
};

Node* split(Node* head) {
  Node* fast = head;
  Node* slow = head;

  while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }

  Node* temp = slow->next;
  slow->next = NULL;
  if (temp != NULL) {
    temp->prev = NULL;
  }
  return temp;
}

Node* merge(Node* first, Node* second) {
  if (first == NULL) return second;
  if (second == NULL) return first;

  if (first->data < second->data) {
    first->next = merge(first->next, second);
    if (first->next != NULL) {
      first->next->prev = first;
    }
    first->prev = NULL;
    return first;
  } else {
    second->next = merge(first, second->next);
    if (second->next != NULL) {
      second->next->prev = second;
    }
    second->prev = NULL;
    return second;
  }
}

Node* mergesort(Node* head) {
  if (head == NULL || head->next == NULL) return head;
  Node* second = split(head);

  head = mergesort(head);
  second = mergesort(second);

  return merge(head, second);
}

void printList(Node* head) {
  Node* cur = head;
  while (cur != NULL) {
    cout << cur->data << " ";
    cur = cur->next;
  }
  cout << endl;
}

int main() {
  Node* head = new Node(10);
  head->next = new Node(8);
  head->next->prev = head;
  head->next->next = new Node(6);
  head->next->next->prev = head->next;
  head->next->next->next = new Node(2);
  head->next->next->next->prev = head->next->next;

  printList(head);

  head = mergesort(head);

  printList(head);
}


