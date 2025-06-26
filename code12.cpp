/*LEETCODE MICROSOFT INTR
SORT COLORS n objs-Green(0),white(1),pink(2) 0s,1s & 2s
1.sort(vec.begin(),vec.end()):-ASC  Brute force  :- O(nlogn)
2.optimzed:-O(n)  [2,0,2,1,1,0,1,2,0,0] 1.count times the num's repeated 2.go on insert in array(2 passes)
    starting :  mid,l               high
3.optimal:-O(n) single pass, Dutch National flag algo 3pointers->low,mid,high
0->0 to l-1, 1->l to m-1 ,unsorted array->m to h-1 ,2->h to n-1
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> sortColor2(vector<int> a){
  int n = a.size();
  int count0=0,count1=0,count2=0;
  for(int i=0;i<n;i++){
    if(a[i]==0)  count0++;
    else if(a[i]==1) count1++;
    else count2++;
  }

  int idx=0;
  for(int i=0;i<count0;i++){
   a[idx++] = 0;
  }
  for(int i=0;i<count1;i++){
   a[idx++] = 1;
  }
  for(int i=0;i<count2;i++){
   a[idx++] = 2;
  }

  return a;
}

vector<int> sortColor3(vector<int> a){
  int n = a.size();
  int low = 0,mid = 0,high = n-1;

  while(mid <= high){
    if(a[mid] == 0){
      swap(a[low++],a[mid++]);
    }else if(a[mid] == 1){
        mid++;
    }else{ // 2
      swap(a[high--],a[mid]);
    }
  }
  return a;
}

int main(){
  vector<int> a = {2,0,2,1,1,0,1,2,0,0};
  vector<int> b = sortColor2(a);
  vector<int> c = sortColor3(a);
  
  for(int val : b){
    cout << val ;
  }
  cout << "\n";
  for(int val1 : c){
    cout << val1  ;
  }
  cout << endl;
  return 0;
}

