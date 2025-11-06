//Leetcode : 3SUM  nums = {-1,0,1,2,-1,-4}
//return triplet a != b != c , a+b+c=0, {-1,0,1} ,{2+-1+-1}
//Brute:- find all triplets 
//Better:-Hashing -TC -O(n^2 * log(uniqueTriplets))
//Best:-2 pointer -TC -O(nlogn(sort) + n^2)
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//Brute force :- O(n^3 * logn)  SC:-O(unique triplets * 2) ans,s both are storing so *2
vector<vector<int>> threeSumB(vector<int> nums){
  int n = nums.size();
  vector<vector<int>> ans;
  set<vector<int>> s;

  for(int i=0 ;i < n; i++){   //a
    for(int j=i+1; j < n; j++){  //b
      for(int k=j+1; k < n ;k++){  //c
        if(nums[i] + nums[j] + nums[k] == 0){
          vector<int> trip = {nums[i] , nums[j] , nums[k]};
          sort(trip.begin(),trip.end());  //sorting ele of vec so that we can avoid storing the permutations of the same values
          
          //set->O(log n) ,unordered set->O(1) => both stores unique elem
          if(s.find(trip) == s.end()){ // Unique , non repeated
            s.insert(trip);
            ans.push_back(trip);           
          }
        }
      }
    }
  }
   return ans;
}

//A + B + C = 0
// B + C = -A => tar = -A
// C = -A - B => C = tar - B
vector<vector<int>> threeSum2(vector<int> nums){
  int n = nums.size();
  set<vector<int>> uniqueTriplets;

  for(int i=0; i<n; i++){
    int tar = -nums[i];    //-A
    set<int> s;

    for(int j=i+1 ; j<n ; j++){
      int third = tar - nums[j];  //C = -(A + B)

      if(s.find(third) != s.end()){  //Finding -(A + B)
        vector<int> trip = {nums[i], nums[j], third};
        sort(trip.begin(),trip.end());
        uniqueTriplets.insert(trip);
      }
      s.insert(nums[j]);
    }
  }
  vector<vector<int>> ans(uniqueTriplets.begin(),uniqueTriplets.end());
  return ans;
}

vector<vector<int>> threeSum3(vector<int> nums){
  int n = nums.size();
  vector<vector<int>> ans;

  sort(nums.begin(),nums.end());

  for(int i=0 ; i<n ;i++){
    if(i > 0 && nums[i] == nums[i-1]) continue;

    int j = i+1, k = n-1;

    while (j < k){
      int sum = nums[i]  + nums[j] + nums[k];
      if(sum < 0){
        j++;
      } else if(sum > 0){
        k--;
      } else{
        ans.push_back({nums[i], nums[j], nums[k]});
        j++; k--;

        while(j < 0 && nums[j] == nums[j-1]) j++;
      }
    } 
  }
  return ans;
}


int main(){
  vector<int> nums = {-1,0,1,2,-1,-4};
  int n = nums.size();
  vector<vector<int>> a = threeSum3(nums);
  // for(int i=0 ;i<n ;i++){ // in o/p there is some garbage value including o/p
  //   for(int j=0;j<n;j++){
  //     cout << a[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  for(const auto& triplet : a){
    for(int num :  triplet){
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}