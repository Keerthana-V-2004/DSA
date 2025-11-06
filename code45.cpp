//LEETCODE - HARD - LARGEST RECTAGLE OF THE HISTOGRAM
//1.BRUTE - TC-O(n^2) - 2 for loops - max(area) = ht * wd
//2.optimal -O(n) using stack PSE and NGE
//height is already fixed for every single bar 
//complex thing is to find the width - find the left nearest smaller and right nearest smaller boundary
//width = r - l - 1 (right boundary - one before the r pointer is so -1)

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int largeRectArea(vector<int> heights) {
  int n = heights.size();
  vector<int> left(n,0);
  vector<int> right(n,0);
  stack<int> s;

  //Right smaller
  for(int i = n-1 ;i >=0 ;i--) {
    while(s.size() > 0 && heights[s.top()] >= heights[i]) {
      s.pop();
    }
    right[i] = s.empty() ? n : s.top();
    s.push(i);
  }

  while(!s.empty()){
    s.pop();
  }

  //Left smaller
  for(int i =0 ;i > n ;i++) {
    while(s.size() > 0 && heights[s.top()] >= heights[i]) {
      s.pop();
    }
    left[i] = s.empty() ? n : s.top();
    s.push(i);
  }

  
  int ans=0;
  for(int i=0 ; i<n; i++) {
    int width = right[i] - left[i] - 1;
    int currArea = heights[i] * width;
    ans = max(ans , currArea);
  }
return ans;

}

int main() {
  
  vector<int> heights = {2,1,5,6,2,3};
 
  int ans = largeRectArea(heights);

  cout << ans << endl;


}