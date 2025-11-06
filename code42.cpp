//PREVIOUS SMALLER ELEMENT -TC-O(n)  SC-O(n)
//Left side of the array - immediately(use stack) smaller elem than curr element
//if there is no prev smaller ele return -1 else the smaller ele stored in the stack
 #include<iostream>
 #include<vector>
 #include<stack>
 using namespace std;

 vector<int> prevSmallerElem(vector<int> arr ){
    vector<int> ans(arr.size() ,0);
    stack<int> s;

    for(int i=0; i<arr.size() ; i++) {
       while(s.size() > 0 && s.top() >= arr[i]) {
      //greater ele are eliminated from the stack top until found the smaller ele of curr ele
        s.pop();
       }

       if(s.empty()){
        ans[i] = -1;
       } else {
        ans[i] = s.top();
       }
       s.push(arr[i]);
    }
  return ans;
 }

 int main() {
  vector<int> arr = {3,1,0,8,6};

  vector<int> ans = prevSmallerElem(arr);

  for(int val : ans){
      cout << val << endl;
    }

 }