//NEXT GREATER ELEMENT -O(n) same as STOCK span
//Right side of the array - immediately(use stack) greater elem than curr element
 #include<iostream>
 #include<stack>
 #include<vector>
 using namespace std;

 int main(){
  vector<int> arr = {6,8,0,1,3};

  stack<int> s;
  vector<int> ans(arr.size(),0);

  for(int i=arr.size();i>= 0;i--){
    while(s.size() > 0 && s.top() <= arr[i]){
  //smaller values are eliminated from the stack top until found the greater ele of curr ele
      s.pop();
    }

    if(s.empty()){
      ans[i] = -1;
    } else {
      ans[i] =s.top();
    }
    s.push(arr[i]);
  }
   for(int val : ans){
      cout << val << endl;
    }
 }