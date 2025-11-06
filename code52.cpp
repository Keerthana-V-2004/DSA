//Circular queue
//same as queue but there is advantage over the normal queue 
//No space is remained unused after the pop from front
//4,2,3 cap=3  rear = (2+1)%3 = 0 again start pointing to the 0th beginning of the queue
//push-rear=(r+1)%cap, pop-front=(f+1)%cap = 
//all functions are of constant time complexity
#include<iostream>
using namespace std;

class CircularQueue {
  int* arr;
  int currSize, cap;
  int f, r;

public:
  CircularQueue(int size) {
    cap = size;
    arr = new int(cap);
    currSize = 0;
    f = 0;
    r = -1;
  }

  void push(int data) {
    if(currSize == cap) {
      cout << "CQ is Full\n";
      return;
    }
    
    r = (r + 1) % cap;
    arr[r] = data;
    currSize++;
  }

  void pop() {
    if(empty()) {
      cout << "CQ is empty\n" ;
    }

    f = (f + 1) % cap;
    currSize--;
  }

  int front() {
    if(empty()) {
      cout << "CQ is empty\n" ;
    }

    return arr[f];
  }

  bool empty() {
    return currSize == 0;
  }

  void printArr() {
    cout << "we print the arr:" ;
    for(int i=0; i<cap ;i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

};
int main() {
  CircularQueue cq(3);

  cq.push(1);
  cq.push(2);
  cq.push(3);

  cq.pop();
  // cq.printArr();

  cq.push(4);

  cq.printArr();

  cout << "How actually they are stored in arr : ";
  while(!cq.empty()) {
    cout << cq.front() << " ";
    cq.pop();
  }
  return 0;
}
