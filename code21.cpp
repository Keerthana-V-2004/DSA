/*String Compression TC:O(n)
chars = ["a","a","b","b","c","c","c"] => return ["a","2","b","2","c","3"] 6
1.continuous chars :-count  a-2,b-2,c-3
2.count == 1 =>ch , count > 1 => "ch"+to_string(count)*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int compress(vector<char> &chars){
  int n = (int)chars.size();
  if(n == 0) return 0; // handle empty input

  int idx = 0;
  for(int i = 0; i < n; i++){   // TC: O(n)
    char ch = chars[i];
    int count = 0;

    while (i < n && chars[i] == ch){
      count++;  i++;
    }

    // write the character
    chars[idx++] = ch;

    // write the count digits (if > 1)
    if(count > 1){
      string str = to_string(count); // convert the int count to string
      for(char dig : str){
        chars[idx++] = dig; // handles multi-digit counts
      }
    }

    i--; // step back so the for-loop's i++ goes to the next new char
  }

  chars.resize(idx); // shrink to compressed length
  return idx;
}

int main(){
  vector<char> chars = {'a','a','b','b','c','c','c'} ;
  int len = compress(chars);
  cout << "compressed string: ";
  for(char c : chars) cout << c;
  cout << "\ncompressed string length: " << len << endl;
}