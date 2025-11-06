/*Reverse Words in string word:-Sequence of non-space chars
s = "the sky is blue", return s = "blue is sky the"
trailing spaces/Multiple spaces "__hello__World__" => "World_hello"  */
 #include<iostream>
 #include<algorithm>
 using namespace std;

 string reverseWords(string s){
  int n = s.length();
  string ans="";

   reverse(s.begin(),s.end()); // dlroW olleh
  /* if(s.length() > 0){
      ans += " " + s;
    }  
    cout << ans << endl;*/
  for(int i=0; i < n ; i++){
    string word = "";
    while (i<n && s[i] != ' '){
      word += s[i];
      i++;
    }

    reverse(word.begin(),word.end()); //World hello
    if(word.length() > 0){
      ans += " " + word;  //" " for adding single space b/w each word
    } 
  }
  return ans.substr(1); //Remove first space due to added for one space bfr every word
 }                      // Taking substr from 1st indx

 int main(){
  string s = "  hello World";
  cout << reverseWords(s) << endl;
 }
