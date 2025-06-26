//LEETCODE 1:- 2 SUM
//arr = [5,2,11,7,15] tag = 9 return [1,3] => 2+7=9 assume single sol
//Brute :- All pairs - sum = tag TC:-O(n*n)
//Better :-   TC:O(nlogn) two pointer approach
//1. sort arr[] O(nlogn) 2. O(n) traverse over arr for sum
//optimized :- Hashing :maps and sets

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int> arr, int tar){
  unordered_map<int,int> m;
  vector<int> ans;

  for(int i=0; i<arr.size(); i++){ // TC:O(n)
    int fst = arr[i];
    int sec = tar - fst;
    
    // constant TC for find fun O(1)
    if(m.find(sec) != m.end()){  // find() fun return T ,else return iterator m.end() 
      ans.push_back(i);      // adding ele to map
      ans.push_back(m[sec]);  
      return ans;
    }
    m[fst] = i; // key : val insert in map
  }
}
int main(){
  vector<int> arr = {5,2,11,7,15};
  int tar = 9;
  cout << "Two Sum:" ;
  vector<int> num = twoSum(arr,tar);
  for(int val : num ){
    cout << val <<" ";
  }
}