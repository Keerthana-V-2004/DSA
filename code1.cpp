// SMALLEST/LARGEST IN ARRAY 
#include<iostream>
#include<climits>//int_max and int_max
using namespace std;

int main(){
  int nums[]={12,23,4,13,-5};
  int size=5;
  int indexS,indexL;
  int smallest=INT_MAX;  //+infinity
  int largest=INT_MIN;   //-inf
  for(int i=0;i<size;i++)
  {
    if(nums[i]<smallest){      //smallest=min(smallest,nums[i]); 
      smallest=nums[i];     //updation of smallest=+inf, 12,4,-5 
      indexS=i;      
   }
    if(nums[i]>largest){      // largest=max(largest,nums[i]);
      largest=nums[i];       //updation of largest=-inf,12,23
      indexL=i;         
    }
  }
  cout << "Smallest= "<< smallest << endl;
  cout << "Smallest value index= "<< indexS << endl;
  cout << "Largest= "<< largest << endl;
  cout << "Largest value index= "<< indexL << endl;
  return 0;
}

// REVERSING ARRAY
#include<iostream>
using namespace std;

void reversearray(int arr[],int sz){
  int start=0,end=sz-1;
    while(start < end){
      swap(arr[start],arr[end]);
      start++;
      end--;
    }
}

int main()
{
  int arr[]={23,45,22,65,45};
  int sz=5;

  reversearray(arr,sz);
  for(int i=0;i<sz;i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
