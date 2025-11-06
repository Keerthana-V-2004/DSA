//TRAPPING RAIN WATER -
//heights = {4,2,0,3,2,5}
//decide the left and right boundary are larger
//NAIVE - TC-o(n^2) as min (lmaxb[ht[i]] , rmaxb[ht[i]]) - ht[i] , 2 for loop
//BETTER -TC -O(n)-SC -O(n)PREFIX ARRAY - 2 AUXILLARY array lmax - 4,4,4,4,4,5 , rmax - 5,5,5,5,5,5 
//left = 4,rgt=5 

//OPTIMAL - TC -O(n) SC-O(1) -TWO POINTER APPROACH

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Trap {
public:
    int trap1(vector<int> ht) {
      int n = ht.size();

      vector<int> lmax(n,0);
      vector<int> rmax(n,0);

      lmax[0] = ht[0];
      rmax[n-1] = ht[n-1];

      for(int i=1; i<n ;i++) {
        lmax[i] = max(lmax[i-1] , ht[i]); //lmax - 4,4,4,4,4,5 
      }

      for(int j=n-2; j>=0 ;j--) {
        rmax[j] = max(rmax[j+1] , ht[j]); // rmax - 5,5,5,5,5,5
      }
      
      int ans = 0;
      for(int i=0; i<n ;i++) {
        ans += (min(lmax[i] ,rmax[i]) - ht[i]) ;
      }
      return ans;
    }
//OPTIMAL -TC-O(n), SC- O(1)
    int trap2(vector<int> ht) {
      int n = ht.size();
      int l=0 , r=n-1;
      int lmax=0 ,rmax=0;
      int ans = 0;

      while(l < r) {
        lmax = max(lmax , ht[l]);
        rmax = max(rmax , ht[r]);

        if(lmax < rmax) {
          ans += lmax - ht[l];
          l++;
        } else {
          ans += rmax - ht[r];
          r--;
        }
      }
      return ans;
    }
};

int main() {
  Trap t;
  vector<int> heights = {4,2,0,3,2,5};

  int ans1 = t.trap1(heights);

  cout << "1.The maximum amount of water can be stored: " << ans1 << endl;

  int ans2 = t.trap2(heights);

  cout << "2.The maximum amount of water can be stored: " << ans2 << endl;

  return 0;

}