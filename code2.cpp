//LINEAR SEARCH ALGO
// TC=O(n)
#include<iostream>
using namespace std;

int linearsearch(int arr[],int sz,int elem){
  for(int i=0;i<sz;i++){
    if(arr[i]==elem){
    return i;  //FOUND
  }
 }
 return -1; // UNFOUND
}

int main(){
  int arr[]={23,45,22,65,45};
  int sz=5;
  int elem=65;
  cout << linearsearch(arr,sz,elem) << endl;
  return 0;
}

