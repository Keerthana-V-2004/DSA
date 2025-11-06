/*2D Array : rows , columns : Matrix
int matriix[row][col]
row major:- if row are stored fst in mem 1,2,3,4,5,6,7,8,9
colm maj:-1,4,7,2,5,8,3,6,9 in mem of 100 104 108 112 118 122 126 130 134*/
#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

//Linear search :-stl pair<row,col>
pair<int,int> linearSrch(int mat[][3],int rows ,int cols, int key){//ret type is bool
  for(int i=0; i<rows ;i++){
    for(int j=0; j< cols ;j++){
      if(mat[i][j] == key){
        return {i,j}; //return true
      }
    }
  }
return {-1,-1}; //return false
}

//Maximum Row Sum
int getMaxSum(int mat[][3], int row,int col){
  int maxSum = INT_MIN;
  for(int i=0; i < row; i++){
    int rowSum = 0;
    for(int j=0; j < col; j++){
      rowSum += mat[i][j];  // colSum += mat[j][i] ,for maximum col sum
    }
    maxSum = max(maxSum, rowSum);
  }
  return maxSum;
}

/*Diagonal Sum :-TC -O(n*n)
Even(4*4) mat no double add of dig ele but in odd(3*3) mat center ele is added twice
we can do it by nested loop but only i is used so no need of j var
primary dig :- i==j,Secondary dig :- j=n-1-i(i-incr and j-decr,pattern matches as j=n-1-i)
 for(int i=0; i < n; i++){
    for(int j=0; j < n; j++){
   PD   if(i == j){       odd mat repaeting ele i==j so it wont added again
        sum += mat[i][j];
   SD   }else if(j == n-1-i){   check for cond for the repeating dig for odd mat
        sum += mat[i][j];    }}} */

// Code optimized to TC:O(n)
int diagonalSum(int mat[][3],int n){ // 1+5+9+3+_+7 -> 5 is skipped 
  int sum = 0;
  for (int i=0 ; i < n ;i++){
    sum += mat[i][i];  //PD and 3*3 repeating dig ele

    if(i != n-1-i){   //SD
      sum += mat[i][n-1-i];
    }
  }
 return sum;
}

int main(){
  int mat[][3] = {{1,2,3},{4,5,6},{7,8,9}}; //declaring colm is neccesary
  int row = 3;
  int col = 3;
  int key = 8;
  pair<int,int> pos = linearSrch(mat,row,col,key) ;
  cout <<"Linear search:"<< pos.first << "," << pos.second << endl;
  cout <<"Maximum row sum:" << getMaxSum(mat,row,col) << endl;
  cout <<"Diagonal Sum:" << diagonalSum(mat,3) << "\n"; // 3 is matrix size

/*2D vector:Dynamic
row = mat.size(), col = mat[i].size() how many col in one row eg:mat[0].size=3 
if want can make matrix resize particular row or col:Dyn sizing no fixed size*/
  vector<vector<int>> mat1 = {{1,2,3},{4,5,6,10,12},{7,8,9}};
  cout << "Vector Matrix:" << endl;
  for(int i=0 ; i < mat1.size() ;i++){
    for(int j=0; j < mat1[i].size(); j++){
      cout <<  mat1[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}