//CELEBRITY PROBLEM
/*At a party with n people:
A celebrity is a person who:
1. Is known by everyone.
2. Knows no one.
We are given a matrix M[n][n] where:

M[i][celeb] = 1 → person i knows person celeb. for all i , so eliminate i
M[celeb][i] = 0 → person celeb does not know person i. for all i
👉 Task: Find the celebrity (return index) or return -1 if no celebrity exists.

Each time we pop the top 2 elem and perform operation and push the celeb to the top*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int getCelebrity(vector<vector<int>> arr) {
  int n = arr.size();
  stack<int> s;
  for(int i=0; i<n ;i++) {
    s.push(i);
  }

  while(s.size() > 1) {
    int i = s.top();
    s.pop();

    int j = s.top();
    s.pop();
    
    if(arr[i][j] == 0) {
      s.push(i);
    } else {
      s.push(j);
    }
  }

  int celeb = s.top();

  for(int i=0 ;i<n ;i++) {
    if(i!=celeb && (arr[i][celeb] == 0 || arr[celeb][i] == 1)) {
      return -1;
    }
  }
return celeb;
}

int main() {
  vector<vector<int>> arr = {{0,1,0},{0,0,0},{0,1,0}};

  int ans = getCelebrity(arr);

  cout << "Celebrity is : " << ans << endl;

  return 0;
}
