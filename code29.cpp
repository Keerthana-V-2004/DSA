//LEETCODE 18- 4 SUM  TC - O(nlogn + n^3)
//arr =[-2,-1,-1,1,1,2,2] tar=0  i!= j != k != l
//OPTIMAL - 2 pointer approach
// 1.sort() the arr
//[-2, -1, -1, 1, 1, 2, 2]
// i  j=i+1 p           q   
//p and q are 2 pointer approach , i ,j+1 for loop

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums,int tar)
{
  vector<vector<int>> ans;
  int n = nums.size();

  sort(nums.begin(),nums.end());  //TC - O(nlogn)

  for(int i = 0 ; i<n ; i++){  // TC - O(n)
    if(i > 0 && nums[i] == nums[i-1]) continue; // optimization for duplicates values

    for(int j =i+1 ; j<n ;){ //O(n)

        int p = j+1 , q = n-1;

        while(p<q){  //O(n)
          long long sum = (long long)nums[i] + (long long)nums[j] + 
                     (long long)nums[p] + (long long)nums[q] ;
          if(sum < tar){
            p++;
          }else if(sum > tar) {
            q--;
          }else {  //sum==tar
            ans.push_back({nums[i],nums[j],nums[p],nums[q]});
            p++; q--;

            while( p < q && nums[p] == nums[p-1]) p++;
          }
        }
        j++;
        while(j < n && nums[j] == nums[j-1]) j++;// optimization 
    }
  }
  return ans;
}
int main()
{
  vector<int> arr = {-2,-1,-1,1,1,2,2};
  int tar = 0;
  vector<vector<int>> a = fourSum(arr, tar);
  for(const auto& quad : a){
    for(int num :  quad){
      cout << num << " ";
    }
    cout << endl;
  }
}