/*String Compression TC:O(n)
chars = ["a","a","b","b","c","c","c"] => return ["a","2","b","2","c","3"] 6
1.continuous chars :-count  a-2,b-2,c-3
2.count == 1 =>ch , count > 1 => "ch"+to_string(count)*/
#include<iostream>
#include<vector>
using namespace std;

int compress(vector<char> chars){
  int n = chars.size();
  int idx = 0;
  cout << "compressed string:" ;
  for(int i=0; i < n; i++){   // for and while loop both are updating i only so TC:O(n)
    char ch = chars[i];  //i(0) = a, i(2) = b ,
    int count = 0;

    while (i < n && chars[i] == ch){
      count++;  i++;
    }
    
    if(count == 1){
      chars[idx] = ch;
      cout << chars[idx++];
    } else{
      chars[idx] = ch;
      cout << chars[idx++];
      string str = to_string(count);// convert the int count to string
      for(char dig : str){  // if count contains double digit
        chars[idx] = dig;
        cout << chars[idx++];
      }
    }
    
    i--; //for get back the idx number to st of next new char aabbccc 1st time idx=2 s0 --
  }
  cout << "\n";
  chars.resize(idx); //resize or compress the vec to compreesed str len
  return idx;
}

int main(){
  vector<char> chars = {'a','a','b','b','c','c','c'} ;
  cout  << "compressed string length:"<< compress(chars) << endl;
}