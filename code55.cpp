//FIRST UNIQUE CHARACTER IN STRING
//str = "level" return the index of char 'v' - 2
//FIFO -queue is used 
//SC-O(n) TC-O(n)

#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class UniChar {
public:
  int firstUniqChar(string s) {
    unordered_map<char , int> m;
    queue<int> q;

    for(int i=0 ; i < s.size() ;i++) {  //O(n)
      if(m.find(s[i]) == m.end()) {
        q.push(i);
      }

      m[s[i]]++;

      while(q.size() > 0 && m[s[q.front()]] > 1) { //running O(n) irrespective of the for loop so TC remains O(n)
        q.pop();
      }
    }
    return q.empty() ? -1 : q.front(); 
  }

};

int main() {

  return 0;
}