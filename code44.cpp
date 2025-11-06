//MIN STACK 2nd approach O(n)
//using global Minval variable we can use one val in stack - O(n)
//val < minVal => val1 = (2 * val      -   minVal) this val1 is stored in the stack not val 
//                         newMin val    old MinVal
//newMin val is stored in stack updated the minVal
//val1 is combination of the curr and prev Minval so we can get both
//if we want to pop the ele we need to reobtain the old Minval by using 
//old MinVal = 2 * new MinVal - val1
//so we can update the minVal to again prev value

//val1(s.top()) < minVal always , minVal is the val should be in the top

#include<iostream>
#include<stack>
using namespace std;
class MinSt {
public:

    stack<long long int> s;  //we are multiple by 2 so to  avoid overflow
    long long int minval;
   

    void push(int val) {
      if(s.empty()) {
        s.push(val);
        minval = val;
      }else {
        if(val < minval) {
          s.push((long long)2*val - minval);
          minval = val;
        } else {
          s.push(val);
        }
      }
    }

    void pop() {
      if(s.top() < minval) {  //update minval if the top elem is minVal
        minval = 2*minval - s.top(); //val1(s.top())
      }
    s.pop();
    }

    int top() {
      if(s.top() < minval) {
        return minval;
      }
      return s.top();
    }

    int getMin() {
      return minval;
    }
};

int main() {
  MinSt s;
  s.push(-2);
  s.push(0);
  s.push(-3);
  s.push(5);
 cout << "{-2,0,-3} :" << s.getMin() << endl;

 cout << "Top ele :" << s.top() << endl;

 s.pop();

 cout << "After pop Top ele :" << s.top() << endl;

 cout << "After pop of top min val:" << s.getMin() << endl;


}