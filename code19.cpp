/*Permutation in String TC:-O(n^2)
s1 = "ab" s2 = "eidbaoo" return true, s1 = "ab" s2 = "eidboaoo" return false
1.Store the frequency of chars in s1 int array , lowercase exists in s1 & s2 :'a'-'z'
If prob is mentioned as for lower ,upper,special,digits store the freq in unordered map<char,int>
s1[i]-'a' => ascii val return the index of array e-a =>101-97 =>4 th ind 0 1 2 3....25
In eng alpha 26 letters 0:a,1:b,2:b,3:c.....,24:y,25:z
2.search s1 permutation in s2:Window based(sliding window)s1.size=2,eidbaooo ei,id,db,ba=>found
window_freq == freq return true else return false*/
#include<iostream>
using namespace std;

bool isFreqSame(int freq1[],int freq2[]){ //TC :constant (26)
     for(int i=0;i < 26 ;i++){
         if(freq1[i] != freq2[i]){
          return false;
         }
     }
     return true;
}
bool checkInclusion(string s1, string s2){
  int freq[26] = {0};

  for(int i=0; i<s1.length();i++){
      freq[s1[i]-'a']++;
  }

  int windSize = s1.length();

  for(int i=0;i<s2.length();i++){
    int windIdx = 0;int idx = i;
    int windFreq[26] = {0};

    while(windIdx < windSize && idx < s2.length()){
      windFreq[s2[idx]-'a']++;
      windIdx++ ; idx++;
    }

    if(isFreqSame(freq, windFreq)){ // found
      return true;
    }
  }
  return false;
}

int main(){
  string s1 = "ab";
  string s2 = "eibadooo";
  cout << "Permutation Found or Not:" << checkInclusion(s1,s2);
  return 0;
}