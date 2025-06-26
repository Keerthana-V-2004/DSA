//Leetcode :-Find missing and Repeating values
//grid = [[9,1,7],[8,9,2],[3,4,6]] 3*3 [1,n^2] [1,9] a->9 2times repeat ,b->5 missing num
//Hashing :- TC: O(n*n)
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

vector<int> findMissAndRep(vector<vector<int>> grid){
  vector<int> ans;
  unordered_set<int> s;
  int n = grid.size();
  int a,b;
  int actualSum = 0, expSum = 0;

  for(int i=0 ; i< n ;i++){ // TC:-O(n^2)
    for(int j=0 ; j < n ;j++){
      actualSum += grid[i][j];  
      if(s.find(grid[i][j]) != s.end()){
        a = grid[i][j];
        ans.push_back(a);
      }
      s.insert(grid[i][j]);
    }
  }
  expSum = (n*n) * (n*n + 1) / 2;
  b = expSum + a - actualSum;
  ans.push_back(b);

  return ans;
}

int main(){
vector<vector<int>> arr = {{9,1,7},{8,9,2},{3,4,6}};
vector<int> a = findMissAndRep(arr);
cout << "Repeat and Missing values:" ;
for(int val : a){
 cout << val << " ";
}
return 0;
}
 