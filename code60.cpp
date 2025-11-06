//SUBSEQUENCE OF STRING 
#include<iostream>
#include<vector>
using namespace std;

void stringSubseq(string &str , string &ans,int i) {
  if(i == str.size()) {
   cout << ans << endl;
   return;
  }

  //Include
  ans.push_back(str[i]);
  stringSubseq(str, ans, i+1 );

  ans.pop_back();

  //exclude
  stringSubseq(str, ans, i+1 );
  
}

int main() {
  string str = "abc";
  string ans ;

  stringSubseq(str, ans, 0);
  
}