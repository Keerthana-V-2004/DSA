//SEARCH IN ROATED SORTED ARRAY
//LEETCODE:-[3,4,5,6,7,0,1,2]LEFT SORTED TAR=0 OR [6,7,0,1,2,3,4,5]RIGHT SORTED
//LINEAR SRC:O(n)  BINARY:O(logn)
//ROATED SORTED ARRAY ATLEAST ONE HALF PART IS SORTED EITHER LEFT OR RIGHT
#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> A, int tar){
  int st=0, end=A.size()-1;

  while(st <= end){
    int mid = st +(end-st)/2;
    if(A[mid] == tar){
      return mid;
    }
  
    if(A[st] < A[mid]){ // LEFT SORTED
      if(A[st] <= tar && tar <= A[mid]){
        end = mid-1;
      }else{
        st = mid +1;
      }
    }else {   // RIGHT SORTED
      if(A[mid] <= tar && tar <= A[end]){
        st = mid+1;
      }else{
        end = mid-1;
      }
    }     
 }
  return -1;
  }

  int main(){
    vector<int> A = {3,4,5,6,7,0,1,2};
    cout << search(A, 0) << endl;
  }
