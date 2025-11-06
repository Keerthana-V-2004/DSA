//Strings :-Valid Palindrome and remove all occurences
//TC:-O(n)
#include<iostream>
#include<cctype> // tolower()
using namespace std;

bool isAlphaNum(char ch){
   if((ch >= '0' && ch <= '9') || 
       (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
        return true;
       }
    return false;   
}

bool isPalindrome(string s){
  int st=0 , end = s.length()-1;

  while(st < end){
    if(!isAlphaNum(s[st])){
      st++; continue;
    }
    if(!isAlphaNum(s[end])){
      end--; continue;
    }
    if(tolower(s[st]) != tolower(s[end])){
      return false;
    }
    st++ ; end-- ;
  }
  return true;
}
 
//Remove Occurances
string removeOccurences(string s, string part){
  while (s.length() > 0 && s.find(part)< s.length()){
    s.erase(s.find(part), part.length());
  }
  return s;
}

int main(){
 string s = "Ac3?e3c&a";
 string s1 = "daabcbaabcbc", part = "abc";
 cout << "Is Palindrome:" << isPalindrome(s) << "\n";
 cout << "Remove Occurences:" << removeOccurences(s1,part);
 return 0;
}