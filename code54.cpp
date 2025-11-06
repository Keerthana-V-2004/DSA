//IMPLEMENT QUEUE USING STACK
//Here we are using 2 stacks as we done before in the 53

#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
  stack<int> s1;
  stack<int> s2;

public:
  void push(int data) {  //O(n)
    while(!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }

    s1.push(data);

    while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
      }
    }

    int pop() {
      int ans = s1.top();
      s1.pop();
      return ans;
    }

    int front() {
      return s1.top();
    }

    bool empty() {
      return s1.empty();
    }

};
int main() {
  MyQueue q;

  q.push(1);
  q.push(2);
  q.push(3);
  
  while(!q.empty()) {
  cout << q.pop() << " ";
  }
  cout << endl;

 return 0;

}