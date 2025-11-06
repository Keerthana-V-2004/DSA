//Design MIN STACK
//2 approachs stack<pair<int,int>> - TC-O(2n) 
//getMin() fun is needed we can't use for loop so, using stack<val,minVal> pair
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class MinStack {
  public:
  stack<pair<int,int>> s;//val,minVal
  
  void push(int val) {
    if(s.empty()) {
      s.push({val,val});
    } else {
      int minVal = min(val, s.top().second);
      s.push({val,minVal});
    }
  }

  void pop() {
    s.pop();
  }

  int top() {
    return s.top().first;
  }

  int getMin() {
    return s.top().second;
  }
};

int main() {
  MinStack s;
  s.push(-2);
  s.push(0);
  s.push(-3);

 cout << "{-2,0,-3} :" << s.getMin() << endl;

 s.pop();

 cout << "Top ele :" << s.top() << endl;

 cout << "After pop of top :" << s.getMin() << endl;


}