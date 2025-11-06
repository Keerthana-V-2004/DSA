//PERMUTATIONS - LEETCODE-46
//nums = {1,2,3} => 1,2,3 - 1,3,2 - 2,1,3 - 2,3,1 - 3,1,2 - 3,2,1 - n!
//Inplace 

#include<iostream>
#include<vector>
using namespace std;

void getPermutation(vector<int> &nums, int idx,vector<vector<int>> &ans ) {
  if(idx == nums.size()) {
    ans.push_back({nums});
    return;
  }

  for(int i=idx; i<nums.size() ;i++) {
    swap(nums[idx], nums[i]); //idx=0-1,2,3 2.idx=1-1,3,2 - 2,1,3 - 3,2,1 for idx=1
    getPermutation(nums, idx+1, ans);

    swap(nums[idx], nums[i]);//backtrack 1.1_ _
  }
}

vector<vector<int>> permute(vector<int> &nums) {
  vector<vector<int>> ans;
  getPermutation(nums, 0 ,ans);
  return ans;
}

int main() {
  vector<int> nums = {1,2,3};

  vector<vector<int>> ans = permute(nums);
  for(const auto& quad : ans){
    for(int num :  quad){
      cout << num << " ";
    }
    cout << endl;
  }

}