//SUBSET 2 -LEETCODE MEDIUM
//duplicate nums = {1,2,2}
//Once we exclude the elem in the call we should not include it again in further any steps if arr[i] == arr[i+1] we have to skip the exclude step

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subsetWithDup(vector<int> &nums , vector<int> &ans,int i,vector<vector<int>> &allSubsets) {
  if(i == nums.size()) {
    allSubsets.push_back(ans);
    return;
  }

  //Include
  ans.push_back(nums[i]);
  subsetWithDup(nums, ans, i+1 , allSubsets);

  ans.pop_back();

  int idx = i+1;
  if(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;

  //exclude
  subsetWithDup(nums, ans, idx , allSubsets);
  
}

vector<vector<int>> getAllSubset(vector<int> &nums ) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> allSubsets;
  vector<int> ans;

  subsetWithDup(nums, ans, 0, allSubsets);
  return allSubsets;

}


int main() {
  vector<int> nums = {1,2,2};

  vector<vector<int>> ans = getAllSubset(nums);
  for(const auto& quad : ans){
    for(int num :  quad){
      cout << num << " ";
    }
    cout << endl;
  }
}