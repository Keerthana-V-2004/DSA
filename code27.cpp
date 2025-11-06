//Leetcode: Find the Duplicate number
//Linked list :- Slow-fast Approach
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int findDupsets(vector<int> nums){ //TC:-O(n) SC:-O(n)
  unordered_set<int> s;
  for(int val : nums){
    if(s.find(val) != s.end()){
      return val;
    }
    s.insert(val);
  }
  return -1;
}

int removeDuplicates(vector<int>& nums) {
  int n = nums.size();
  int i = 1;
  for(int j=1 ;j <n ;j++) {

    if(nums[j] != nums[i-1]) {
      nums[i] = nums[j];
      i++;
    } 
  }
  return i; 
}


int findDuplicate(vector<int> arr){ // TC:-O(n) SC:-O(1)
  int slow = arr[0] ,fast = arr[0];

  do{
    slow = arr[slow];     //+1
    fast = arr[arr[fast]]; //+2
  }while(slow != fast);

  slow = arr[0];

  while(slow != fast){
    slow = arr[slow]; // +1
    fast = arr[fast]; // +1
  }
  return slow;
}

int main(){
  vector<int> nums = {1,3,4,2,2};
  cout << "using unordered_set:" << findDupsets(nums) << "\n";
  cout << "Slow-fast:" << findDuplicate(nums);
  vector<int> nums1 = {0,0,1,1,1,2,2,3,3,4};
  cout << "\nRemove Duplicates from sorted array:" << removeDuplicates(nums1) << "\n";
  return 0;
}
