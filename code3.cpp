// BINARY SEARCH ALGO
//TC=O(log n)

// ITERATIVE
#include<iostream>
#include<vector>
using namespace std;

int bs(vector<int> arr,int tar){
  int st=0, end=arr.size()-1;
  while(st <= end){
    int mid = st + (end-st)/2; //OPTIMIZED MID FOR LARGE INPUTS

    if(tar > arr[mid]){ //RIGHT
      st = mid + 1;
    }else if(tar < arr[mid]){//LEFT
      end = mid - 1;
    }else{
      return mid;
    }
   }
   return -1;
}

//RECURSION
int rbs(vector<int> arr,int tar,int st,int end){
  if(st <= end){
    int mid = st + (end-st)/2;

    if(tar > arr[mid]){  // RIGHT
      return rbs(arr,tar, mid+1,end);
    }else if(tar < arr[mid]){    //LEFT
      return rbs(arr,tar, st,mid-1);
    }else{
      return mid;
    }
  }
  return -1;
}

int main(){
  vector<int> arr1={-1,0,3,4,5,9,12};  //ODD
  int tar1=12;

  vector<int> arr2={-1,0,3,5,9,12};  //EVEN
  int tar2=3;
  int st=0;
  int end=arr1.size()-1;
  
  cout << bs(arr1,tar1) << endl;
  cout << rbs(arr1,tar1,st,end) << endl;

  cout << bs(arr2,tar2) << endl;
  cout << rbs(arr1,tar2,st,end) << endl;
  }