//MAXIMUM SUBARRAY SUM  TC:O(n)
//KADANES ALGO(Optimize):-Large -ve or -ve sum will decr' the sum so neglet the -ve sum numbers 
//{3,-4,5,4,-1,7,-8} 3-4=-1 reset currsum to 0,add 0+5=5,5+4=9,9-1=8,8+7=15,here maxsum=15,15-8=7 so 15
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubArray(vector<int> nums){
  int maxsum=INT_MIN ,currsum=0;
  for(int val : nums){
    currsum += val;
    maxsum=max(currsum,maxsum);

    if(currsum < 0){
      currsum = 0;
    }
  }
  return maxsum;
}

int main(){
  vector<int> arr={3,-4,5,4,-1,7,-8};
  cout << maxSubArray(arr) << endl;
  return 0;
}