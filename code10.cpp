//PROD OF ARRAY EXCEPT SELF
//nums=[1,2,3,4] ans=[24,12,8,6] mul of all nums/val at index 24/1,24/2,24/8,24/6 ,but / is not allowed
//Brute=O(n 2) if(i!=j) prod[i]*=nums[j]
//Optimal=O(n)~O(3n) left(*) * rigt(*)  pfx[i]=pfx[i-1]*nums[i-1]
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> prodexpself(vector<int> nums){
   int n = nums.size();
   vector<int> ans(n,1);
   vector<int> pfx(n,1);
   vector<int> sfx(n,1);

   for(int i=1;i<n ;i++){     //O(n)
    pfx[i]=pfx[i-1]*nums[i-1];
   }
   for(int i=n-2 ;i>=0 ;i--){   //O(n)
    sfx[i]=sfx[i+1] * nums[i+1];
   }
   for(int i=0;i<n ;i++){      //O(n)
    ans[i]=pfx[i]*sfx[i];
   }

return ans;
}

int main()
{
  vector<int> nums={1,2,3,4}; 
  vector<int> a = prodexpself(nums);
  for(auto val:a){
  cout <<  val << endl;
  }
  return 0;
}