/*Search in 2D matrix:-using Binary search TC:-O(log(n*m))
Brute :-Linear search O(n*n)
non-overlapping
Each row is sorted in non-decreasing order
The first integer of each row is greater than the last integer of the previous row*/
#include<iostream>
#include<vector>
using namespace std;

bool searchInRow(vector<vector<int>> mat, int tag , int row){ // O(logn)
  int n = mat[0].size();
  int st = 0, end = n-1;

  while(st <= end){
    int mid = st + (end - st)/2;
    if(tag == mat[row][mid]){
      return true;
    } else if(tag > mat[row][mid]){
      st = mid + 1;
    }else{
      end = mid -1;
    }
  }
  return false;
}

bool searchMatrix(vector<vector<int>> mat ,int tag){ // O(logm)
  //BS on total rows
  int m = mat.size(), n = mat[0].size(); //m is no of colms,n is rows
  int stRow = 0, endRow = m-1;
  while(stRow <= endRow){   //selecting entire row in the matrix
    int midRow = stRow + (endRow - stRow)/2;  //midlle row in the matrix

    if(tag >= mat[midRow][0] && tag <= mat[midRow][n-1]){
      return searchInRow(mat, tag, midRow);  //this will search in the row
    } else if(tag >= mat[midRow][n-1]){
      //down => right
      stRow = midRow + 1;  //move to down row of the matrix
    }else{
      //up => left
      endRow = midRow - 1;
    }
  }
  return false;
}

/*Search in 2D mat II:-m*n  TC:-O(n+m)
For mat = {{1, 4, 7, 11, 15}
          ,{2, 5, 8, 12, 19}
          { 3, 6, 9, 16, 22},
          {10,13 14, 17, 24},
          {18,21 23, 26, 30}}
integers in each row are sorted in ascending from left to right
integers in each col are sorted in ascen from top to bottom
Rows are overlapping
Lowest val [0][0], highest val[m-1][n-1]
mid val is taken as corner val 15 or 18  */
bool srcMat(vector<vector<int>> mat, int tag){
  int n = mat.size(), m = mat[0].size();

  int r = 0, c = n-1;
  while (r < m && c >= 0){
    if(tag == mat[r][c]){
      return true;
    }else if (tag < mat[r][c]){  //descard entire col
      c--;
    }else {                   //descard entire row
      r++;
    }
  }
  return false;
}


int main(){
  vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
  int tag = 34,tag2 = 5;
  cout << "Search for target:" << searchMatrix(mat,tag) << "\n";
  vector<vector<int>> mat2 = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
  cout << "Search mat2:" << srcMat(mat2,tag2) << endl;
  return 0;
}