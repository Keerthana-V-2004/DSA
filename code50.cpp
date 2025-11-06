//QUEUE - FIFO - front-pop ,rear-adding - using linked list
//enqueue - push , dequeue - pop , front
//front - head->data , push - to the head , pop - at the tail end

#include<iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;

  Node(int val) {
    data = val;
    next = NULL;
  }
};

class Queue {
  Node* head;
  Node* tail;

public:
  Queue() {
    head = tail = NULL;
  }

  void push(int data) { //insert data at tail- O(1)
    Node* newNode = new Node(data);
    if(empty()) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }

  }

  void pop() {
    if(empty()) {
      cout << "Linked is empty" << endl;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  int front() {
    if(empty()) {
      cout << "Linked is empty" << endl;
      return -1;
    }
    return head->data;
  }

  bool empty() {
    return head == NULL;
  }
};

int main() {
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);

  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
  return 0;
}