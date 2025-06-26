/*Character Arrays:-Cstrings, char str[]={'a','b','c'}, store strings char str[]={'a','b','c','\0'}
each character is of a, b, c,\0 1B memo including '\n' 
char str[] is constant pointer: abc, int arr[] return address
strlen is 3 '\0' is ignored
char str[] = "hello" explicitly ended with '\0' strlen:5 :- String Literal ,which value doesn't change
index retrival is allowed str[2]=l, str[5]=_('\0')
Character array I/O :-
cin :-/ignores the character after the space 
cin.getline(str,len,delim?):-accept whitespace also (char arr,no of char,aft delimiter stop taking i/p)
default delimiter is \n new line or ENTER press*/

#include<iostream>
using namespace std;

int main(){
  char str[50],str1[50];

  cout << "Enter the char arr:" ;
  cin >> str;
  cout << "cin:" << str << endl;
  cout << "Enter the string:" ;
  cin.ignore();
  cin.getline(str1,15,'.');
  cout << "cin.getline():" << str1 << endl;

  char s1[] ="Hello world";
  int len = 0;
  cout << "Using for each loop:";
  for(char ch : s1){
    cout << ch ;
  }
  cout << endl;

  for(int i=0 ; s1[i] != '\0' ; i++){
      len++;
  }
  cout << "Length of the s1:" << len << "\n";
 

/* Strings in CPP
IN-BUILT String class :- can create obj assign to string literals
#include<string> optional 
Dyanamic in nature :- Resize at runtime , contiguous allocation */
string s2 = "Hello world";
cout << "bef reallo:" << s2 << "\n";

s2 = "Hyy Guys";
cout << "Aft reallo:"<< s2 << "\n";

//char chArr[] = "HEllo"; ERROR:-It is not a modifiable value in runtime
//chArr = "hYY";

// Concatenation 
string s3 = s1 + s2;
cout << s3 << "\n";
//Comparision
cout << "Comparision:"<< (s1 == s2) << "\n"; // > ,< ,>=,<= also...
cout << s3.length() << "\n";
//['h','e','l','l','o'] == ['h','e','l','l','o']it is not possible , need for loop and it is difficult 

string s4;
cout << "String class cin:";
cin >> s4;
cout << "String cin:" << s4 <<  "\n";
string s5;
cout << "String class getline:";
cin.ignore(); //the leftover'\n'from cin previous input which remains in input buffer and getline reads an empty line
getline(cin, s5);
cout << "String getline" << s5 << "\n";
 return 0;
}