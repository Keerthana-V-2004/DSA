//IMPLEMENT STACK USING QUEUE -LEETCODE 225
//we need 2 queue to implement
//push or pop either one is going to have the O(n) TC 
//bcz LIFO and FIFO are opposite to each other
//q1-1  top=q1.front() so we have to insert 2 on top of q1 it's not possible to insert at front so we need to copy all the elem of q1 to q2 insert elem to q1
// again we push the elem back to q1
//q2-1 => q1-2,1

#include<iostream>
#include<queue>
using namespace std;

class MyStack {
  queue<int> q1;
  queue<int> q2;

public:
  void push(int data) { //O(n)
    while(!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }

    q1.push(data);
    
    while(!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
  }

  int pop() {
    int ans = q1.front();
    q1.pop();
    return ans;
  }

  int top() {
    return q1.front();
  }

  bool empty() {
    return q1.empty();
  }

};
int main() {
  MyStack s;

  s.push(1);
  s.push(2);
  s.push(3);

  while(!s.empty()) {
    cout << s.pop() << " ";
  }
  cout << endl;

  cout << s.top() ;

  return 0;
}

