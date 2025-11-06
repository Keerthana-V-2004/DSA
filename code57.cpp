//RECURSION
//TC - TOTAL NO OF CALLS * WORKDONE IN EACH CALL
#include<iostream>
#include<vector>
using namespace std;

//check if array is sorted 
bool isSorted(vector<int> arr, int n) {
  if(n==0 || n==1) return true;

  return (arr[n-1] >= arr[n-2] && isSorted(arr, n-1));
}

//Factorial
int fac(int n) {
  if(n==0) return 1;

  return n*fac(n-1);
}

//FIBONACCI -TC-O(2^n) EXPONENTIAL
int fib(int n) {
  if(n==0 || n==1) return n;

  return fib(n-1)+fib(n-2);
}

//PRINT SUBSETS -TC -O(2^n * n) n size arr will have 2^n subsets, for reach  every subset end we have to travel n => height of the recursive tree
//each level we are going to take the single elem and subset 
//2 options where once it include once it exclude
//we are taking levels as a index (i+1)
void printSubsets(vector<int> &arr , vector<int> &ans , int i) {//address of the ans bcs we need to modify with in the same vector for each call of the recursion
  if(i == arr.size()) {
    for(int val : ans) {
      cout << val << " " ;
    }
    cout << endl;
    return;
  }

  //Include
  ans.push_back(arr[i]);
  printSubsets(arr, ans , i+1);  //after every base case hit it returns 1.{1,2,3} 2.{1,2,3} ,3.

  ans.pop_back(); // backtrack 1.pop(3) 2.pop(2)  

  //exclude
  printSubsets(arr, ans , i+1); //1.ans => {1,2} bcz 3 is popped 

}
int main() {
  vector<int> arr = {1,2,3};
  vector<int> ans;
  cout << isSorted(arr, 3) << endl;

  cout << fac(3) << endl;

  cout << fib(4) << endl;

  printSubsets(arr,ans,0);


  return 0;

}