#include <iostream>

class Node {
  public:
    int data;
    Node* next;

    // constructors
    Node() {
      data = 0;
      next = NULL;
    }

    Node(int val) {
      data = val;
      next = NULL;
    }
};

class LinkedList {
  public:
    Node* head;

    LinkedList() {
      head = NULL;
    }

    void append(int val) {
      Node* newNode = new Node(val);
      if (head == NULL) {
        head = newNode;
        return;
      }
      Node* curr = head;
      while (curr->next != NULL) {
        curr = curr->next;
      }
      curr->next = newNode;
    }

    void print() {
      Node* curr = head;
      if (curr == NULL) {
        std::cout << "list empty" << std::endl;
        return;
      }
      while (curr != NULL) {
        std::cout << curr->data << ", ";
        curr = curr->next;
      }
      std::cout << std::endl;
    }

    Node* delete_helper(int val, Node* prev) {
      if (prev == NULL || prev->next == NULL) return NULL;
      if (prev->next->data == val) {
        Node* to_delete = prev->next;
        prev->next = to_delete->next;
        to_delete->next = NULL;
        return to_delete;
      }
      return delete_helper(val, prev->next);
    }

    Node* delete_item(int val) {
      if (head == NULL) return NULL;
      if (head->data == val) {
        Node* to_delete = head;
        head = head->next;
        to_delete->next = NULL;
        return to_delete;
      }
      return delete_helper(val, head);
    }

    Node* reverse_helper(Node* start) {
      if (start == NULL) return NULL;
      if (start->next == NULL) return start;
      Node* new_head = reverse_helper(start->next);
      start->next->next = start;
      start->next = NULL;
      return new_head;
    }

    void reverse() {
      head = reverse_helper(head);
    }
};

int main() {
  LinkedList list;
  list.print();
  for (int i = 0; i < 10; i++) {
    list.append(i);
  }
  list.print();

  list.delete_item(6);
  list.delete_item(7);

  list.print();

  list.reverse();
  list.print();
};
