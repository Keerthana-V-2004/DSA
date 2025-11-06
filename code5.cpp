//LEETCODE PROB
//COMPUTE X^n :- BRUTE O(n)  10^8 OPS<< 2^31 TLE DOESN'T EXECUTE
//USING BINARY EXPONENTIATION:-IF n digits = logn+1 binary form digits  O(logn)
/*3^5 : 5BF   1   0   1     x=3, x^2=3.3=3^2, (x^4)=3^2.3^2=3^4 ,(x^8)=3^4.3^4 here only 4 iteratoins 
            =3^4 3^2 3^1                                                    instead of 8 iterations
            =3^4*3^1      iteration=log5 +1 = 3
            =3^5    */
#include<iostream>
using namespace std;

long pow(double x,int n){

  // corner cases

  long binform = n;
  if(n < 0){      //constant
    x=1/x;
    binform = -binform;
  }

  double ans = 1;
  while(binform > 0){ // O(logn)
    if(binform % 2 == 1){ //if it is odd no 5%2==1(1), 2%2!=1(0),1%2==1(1)
      ans = ans * x;     //1.3 ,_,3.81 
    }
    x*=x;  //next binary position = next pow of 2 update 3.3=9  ,9.9=81 ,81.81
    binform /= 2; //move to next bit update  5/2=2, 2/2=1
  }
  return ans;
}

int main(){
  double x=5;
  int n=4;
  
  cout << pow(x,n) << endl;
}
