/*SORTING ALGO
Bubble sort:-O(n^2) find largest ele (adjacent) in array and place it in original positn
Selection sort:-O(n^2) find the smallest (adjacent) ele in array and place it in original positn
Insertion sort:-O(n^2) divide into sorted and unsorted array 1st ele is sorted array remaining unsorted
compare the unsorted array 1st ele with sorted array last ele if it is smaller tn shift else last2ndele is
checked for condtn  */

#include<iostream>
#include<vector>

using namespace std;

vector<int> bubbleSort(vector<int> arr,int n){
  for(int i=0;i<n-1;i++){

    for(int j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
         swap(arr[j],arr[j+1]);
    }
 }   
  }
  return arr;
}

vector<int> selectionSort(vector<int> arr,int n){
  for(int i=0;i<n-1;i++){
    int smallestInd = i;  //unsorted array starting ind
    for(int j=i+1;j<n;j++){
      if(arr[j] < arr[smallestInd]){
        smallestInd = j;
      }
    }
    swap(arr[smallestInd],arr[i]);
  }
  return arr;
}

vector<int> insertionSort(vector<int> arr,int n){
    for(int i=1;i<n;i++){
      int prev = i-1;
      int curr = arr[i];

      while (prev>=0 && arr[prev] > curr)
      {
       arr[prev+1]=arr[prev];
       prev--;
      }
      arr[prev+1] = curr;
    }
  return arr;
}

int main(){
  int n=5;
  vector<int> arr = {4,2,5,1,3};

   vector<int> a = insertionSort(arr,n);
   vector<int> a1 = selectionSort(arr,n);
   vector<int> a2 = bubbleSort(arr,n);
  for(auto val : a){
    cout << val ;
  }
  cout << endl;
  for(auto val : a1){
    cout << val ;
  }
  cout << endl;
  for(auto val : a2){
    cout << val ;
  }

}