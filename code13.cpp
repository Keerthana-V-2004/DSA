/*LEETCODE MERGE 2 SORTED ARRAYS 
1.A=[1,2,3] B=[2,5,6] c=[1,2,2,3,5,6] extra space O(nlogn)
2.A=[1,2,3,0,0,0] m=3 B=[2,5,6] n=3 from backwards of array  O(m+n) O(1) in place
         i    idx            j 
1.A=[4,5,6,0,0,0] B=[1,2,3]  1.case i<0 copy (remain)B to A 2.case j<0 k,bcz A is already sorted
*/ 

#include<iostream>
#include<vector>
using namespace std;

vector<int> mergeArr(vector<int> A,int m,vector<int> B,int n){
  int i = m-1, j = n-1, idx = m+n-1;

  while(i >= 0 && j >= 0){
    if(A[i] >= B[j]){
      A[idx--] = A[i--];
    } else{
      A[idx--] = B[j--];
    } 
  }

  while(j >= 0){
    A[idx--] = B[j--];
  }
  return A;
}

int main(){
  int n=3,m=3;
  vector<int> A ={1,2,3,0,0,0};
  vector<int> B ={2,5,6};
  vector<int> c =mergeArr(A,m,B,n);
  for(int val : c){
    cout << val ;
  }
  cout << "\n";
  return 0;
}
