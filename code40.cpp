//STOCK SPAN - Stack -O(n + n(while)) ~ O(n)
//prices = {100,80,60,70,60,75,85}
//span - max no of concecutive days from today where price <= todays price includes today price
//prevHigh - Immediate greater previous value 
//between curr and prevahigh there will be only <= values
//span = curridx - prevHighidx
// if it is first value then it has no prevHigh in the stack so it is consider as
//span = curr + 1 also when there is no PrevHigh in the middle of span [20,10,30]
//30 dont have prevHigh these are corner cases

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
  vector<int> price = {100,80,60,70,60,75,85};

  vector<int> ans(price.size(),0); // ans vector is limit the size to price vector
                                  // and init the values with 0
  stack<int> s;
  
  for(int i=0 ; i<price.size() ;i++){   //O(n)
    while(s.size() > 0 && price[s.top()] <= price[i]){ // not to be O(n) it is const
      s.pop();
    }

    if(s.empty()){
      ans[i] = i+1;  // Corner cases
    } else {
      ans[i] = i - s.top(); // curridx - prevHighidx
    }

    s.push(i);
  }
  cout << "Stock Span :";
  for(int val : ans){
    cout << val << " ";
  }
  cout << endl;
  return 0;
}