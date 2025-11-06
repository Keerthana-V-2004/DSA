//LEETCODE 40 - SUBARRAY SUM EQUALS K
//arr = [9,4,20,3,10,5] K=33 count of sub arr's
//1.BRUTE - TC-O(n^2) - 1.sum of all subarr 2.subarr sum = k
//**2.OPTIMAL - HASHING  - TC -O(n)  SC-O(n)
//nested loops are avoided to calu subarr sum - By PREFIX SUM
//[10,20,30,40,50] ps[i=1]=30 ,ps[j=3]=100
//subarr sum(i,j) == ps[j] - ps[i-1]  =>[30,40] = ps[3] - ps[1] = 70
//subarr sum's == K
//K = ps[j] - ps[i-1]  ||  sum(i,j) == ps[j] - ps[i-1]
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 
int subArraySumB(vector<int>& arr , int K){
  int n = arr.size();
  int count = 0;

  for(int i=0 ;i<n ;i++){ //Strating point
    int sum = 0;
    for(int j=i ;j<n ;j++){//ending
      sum += arr[j];
      if(sum == K) count++;
    }
  }
  return count;
}

int subArraySumO(vector<int> arr, int K){
  int n = arr.size();
  int count = 0;
  vector<int> prefixSum(n,0);

  prefixSum[0] = arr[0];
  for(int i=1;i<n;i++){
    prefixSum[i] = prefixSum[i-1] + arr[i]; //9,13,33,36,46,51
  }

  unordered_map<int,int> m; // ps ,freq
  for(int j=0 ;j<n;j++){
    if(prefixSum[j] == K) count++;  // direct 33

    int val = prefixSum[j] - K;     //46-33 = 13
    if(m.find(val) != m.end()){     //there is a subarr which will give the sum as K
      count += m[val];          
    }

    if(m.find(prefixSum[j]) == m.end()){ //Freq - value not found means we cant get K val
      m[prefixSum[j]] = 0;
    }

    m[prefixSum[j]]++;
  }
  return count;
}

int main(){
  vector<int> arr = {9,4,20,3,10,5};
  int K = 33;
  int a = subArraySumB(arr,K);
  cout << a << endl;
}