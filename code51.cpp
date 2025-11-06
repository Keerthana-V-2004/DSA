//Queue stl
//Deque - double ended queue
//push - back , front and pop- front ,back

#include <iostream>
#include <queue>
#include<deque>
using namespace std;

int main() {
  queue<int> q;

  q.push(1);
  q.push(2);
  q.push(3);

  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;

  deque<int> dq;

  dq.push_back(1);
  dq.push_back(2);
  dq.push_front(3);
  dq.push_front(4); // 4,3,1,2

  cout << dq.front() << " " << dq.back() << endl;

  dq.pop_back(); //4,3,1

  cout << dq.front() << " " << dq.back() << endl;

  return 0;
}