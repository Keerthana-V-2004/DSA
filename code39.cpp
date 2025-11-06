//VALID PARENTHESIS - STACK DS -LIFO
//last opening brkt => first closing brkt
//s1 = "({[]}[])"-V  s2="({])"-IV  s3="({}]"-IV
//opening brs == closing brs
//opening brs < closing brs => check for stack empty before the matches found
//opening brs > closing brs => return true only if stack is empty
//all opening brs are push into stack and match them with closing brs 
//if matches pop opening brs from stack if any opening bras are found in middle
//those are push to stack

#include<iostream>
#include<stack>
using namespace std;

class Stack {

public:

   bool isValid(string str){
    stack<char> st;
    
    for(int i=0 ; i<str.size(); i++){
      if(str[i] == '(' || str[i] == '{' || str[i] == '['){ //opening
        st.push(str[i]);
      }
      else {
        if(st.size() == 0){  // closing > opening
          return false;
        }

        if((st.top() == '(' && str[i] == ')') ||  //fing if it matches or nor
           (st.top() == '[' && str[i] == ']')||
            (st.top() == '{' && str[i] == '}' )) {
                 st.pop();
          } else {     //no match
            return false;
          }   
      }
    }
    return st.size() == 0;  // opening > closing
   }

};

int main(){
  Stack s;
  string str1 = "({[()][]})";
  bool ans1 = s.isValid(str1);

  cout << "Is '({[()][]})' valid parenthesis : " << ans1 << endl;

 string str2 = "({)][})";
  bool ans2 = s.isValid(str2);

  cout << "Is '({()][})' valid parenthesis : " << ans2 << endl;
  return 0;
}