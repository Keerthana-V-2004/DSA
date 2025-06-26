/*LEETCODE  NEXT PERMUTATION
A=[1,2,3] (6) return Lexicographically next, in place
BRUTE :- O(n!*n) recussion:find all the permutn and find lex nxt permtn 
OPTIMAL :-O(n) O(1) 123654 3<6 aft 3 dec order 1.find pivot 123654:3 is pivot ,12543:here 2 is pivot,
 2.swap(large just aft pivot,pivot ele)  124653
 3.reverse(pivot+1) to n-1 dec->inc  124356
 A=[5,4,3,2,1] pivot=-1 thn return rearranged lowest possible order(asc ord)
 STL:built-in next_permutation(); function
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nxtPerm(vector<int> A){
  //Find the pivot
  int pivot=-1, n=A.size();
  for(int i=n-2;i>=0;i--){
    if(A[i] < A[i+1]){
      pivot = i;
      break;
    }
  }
  
  if(pivot == -1){
    reverse(A.begin(),A.end()); // inplace changes
  }
  // 2nd step : next largest ele
  for(int i=n-1;i > pivot;i--){
    if(A[i] > A[pivot]){
      swap(A[i],A[pivot]);
      break;
    }
  }
 
 //3rd step : reverse (pivot+1) to n-1
 // reverse(A.begin() + pivot+1,A.end());
  int i=pivot+1,j = n-1;
  while(i <= j){
    swap(A[i++],A[j--]);
  }
  return A;
}

int main(){
  vector<int> A = {1,2,3,6,5,4};
  vector<int> b = nxtPerm(A);
  for(int val : b){
    cout << val;
  }
  cout << endl;
  return 0;
}