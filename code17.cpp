//Reverse a String
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  vector<char> str = {'h','e','l','l','o'};
  int st = 0, end = str.size()-1;// two pointer approach
  while(st < end){
    swap(str[st++],str[end--]);
  }
  cout << "Array:" ;
  for (char ch : str){
    cout << ch;
  }
  cout << endl;

  string sr = "hyy guys";
  reverse(sr.begin(), sr.end()); //Iterators
  cout << "String :" << sr << endl;
  return 0;
}
