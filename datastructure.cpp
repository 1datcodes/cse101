#include <iostream>

class Node {
  public:
    int data;
    Node* next;

    Node() {
      this->data = 0;
      this->next = NULL;
    }

    Node(int val) {
      this->data = val;
      this->next = NULL;
    }
};

class LinkedList {
  public:
    Node* head;

    LinkedList() {
      this->head = NULL;
    }

    void insertAtHead(int val) {
      Node* newNode = new Node(val);
      if (head == NULL) {
        head = newNode;
        return;
      }
      newNode->next = this->head;
      this->head = newNode;
    }

    Node* deleteAtHead() {
      if (head == NULL) return NULL;
      Node* toDelete = head;
      head = head->next;
      toDelete->next = NULL;
      return toDelete;
    }

    void print() {
      if (head == NULL) std::cout << "Empty";
      Node* cur = head;
      while (cur != NULL) {
        std::cout << cur->data << " ";
        cur = cur->next;
      }
      std::cout << std::endl;
    }
};

class Stack {
  public:
    LinkedList stack;

    void push(int val) {
      stack.insertAtHead(val);
    }

    int pop() {
      Node* top = stack.deleteAtHead();
      return top->data;
    }
};

int main() {
  LinkedList list;
  list.print();
  for (int i = 0; i < 10; i++) {
    list.insertAtHead(i);
  }
  list.print();
  Node* deleted = list.deleteAtHead();
  std::cout << deleted->data << std::endl;
  list.print();

  Stack stack;
  for (int i = 100; i < 120; i++) {
    stack.push(i);
  }
  std::cout << stack.pop() << std::endl;
}
