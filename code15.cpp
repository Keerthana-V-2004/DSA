//DSA MATHS
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
string isPrime(){  // check the no is prime or not
  int n=42;
  for(int i=2;i*i < n;i++){
    if(n % i == 0)
      return "Non prime";
  }
  return "prime";
}

/*Sieve of Erathosthenes:- count primes 1 to n
assume all are prime no (1 to n)thn discard multiples of 1)2 mul's,including 4 upto n's is removed
2)3 mul's, 3)5 mul's check for remaining prime numbers that are not multiple of any considered earlier 
prime nums, that includes 2,3,5,7 and so on i.e all remaining ele are prime numbers  */
int countPrimes(int n){
  vector<bool> isprime (n+1,true);
  int count=0;
  for(int i=2; i<n ;i++){
    if(isprime[i]){
      count++;

      for(int j=i*2; j<n; j=j+i){  //runs till eliminate all the multiples of 2 in 1st step
        isprime[j] = false;    //next step allows only the non-mul of the 2
      }
    }
  }
return count;
}

bool isArmstrong(int n){
  int copyN = n;
  int sumOfCubes = 0;

  while (n != 0)
  {
   int dig = n % 10;
   sumOfCubes += (dig *dig * dig);

   n = n / 10;
  }
  return sumOfCubes == copyN;
}
/*(BETTER)EUCLIDS ALGO FOR GCD:- gcd(a,b) = gcd(a-b,b) a > b , => gcd(a,b-a) b>a
gcd(20,28)-> gcd(20,8)  ->gcd(12,8)  ->gcd(4,8)  ->gcd(4,4)  ->gcd(0,4)
Repeated sub => division these steps can be reduced by the modulo oper 
gcd(a,b) = gcd(a%b,b) a > b , => gcd(a,b%a)  b > a 
modulo gcd(20,28) -> gcd(20,8) ->gcd(4,8) ->gcd(4,0)*/

int GCD(int a, int b){
  while (a>0 && b>0){
    if(a > b){
      a = a % b;
    } else {
      b = b % a;
    }
  }
  if (a == 0) return b;
  return a;
}

int gcdRec(int a,int b){ // assuming a as large
  if(b == 0) return a;

  return gcdRec(b, a % b); // always % 'll reduce the val so
}

// LCM :- LOWEST COMMON MULTIPLE
//a*b = gcd(a,b)*lcm(a,b)  => lcm = (a*b)/gcd(a,b)
int lcm (int a,int b){
  int gcd = gcdRec(a,b);
  return (a*b)/gcd;
}

// Reverse a number
int reverse(int n){
  int revNum = 0;

  while(n!=0){
    int dig = n % 10;  // 7563 % 10 = 3 ,756 % 10 = 6, 75 % 10 = 5
    if(revNum > INT_MAX || revNum < INT_MIN){  // out of range of int condition return 0
      return 0;
    }
    revNum = revNum * 10 + dig ; // 0+3=3 , 30+6=36, 360+5=365
    n = n / 10;  // 7563 / 10 = 756, 75
  }
  return revNum;
}

// Check palindrome non negative num
// reverse num == num 
bool isPalindrome(int n){
   if(n < 0) return false;

   int revNum = reverse(n);
   return n == revNum ;
}

int main(){
  cout <<"isPrime:"<< isPrime() << "\n";
  
  int n = 50;
  cout << "count of primes 50 in N:" << countPrimes(n) << "\n";
  
  //isArmstrong:- the number is equal to sum of cubes of the its digits 153,371,1  153=1+125+27

  int A = 153;
  if(isArmstrong(A)){
    cout << "Is an armstrong number" << "\n" ;
  } else{
    cout << "Not an armstrong number" << "\n";
  }

 /* BRUTE :-TC=O(min(a,b))   Gcd greatest common divisor HCF highest common factor
  a=20,b=28 20=2*2*5*1 28=2*2*7*1 =>4 is comman factor
 worst GCD=1 upto min{a,b} a==0 GCD=b, b==0 GCD=a ,a==b GCD=a/b  */
 int gcd = 1, a=20,b=28;
 for(int i=1 ; i <= min(a,b); i++){
     if(a % i == 0 && b % i == 0){
      gcd = i;
     }
 }
 cout << "GCD:" << gcd << "\n";
// Euclids gcd
cout << "Euclids Iterative:" << GCD(a,b) << "\n";
cout << "Euclids Recursion:" << gcdRec(a,b) << "\n";
// LCM 
cout << "LCM:" << lcm(a,b) << "\n";

//Reverse a number
int c = 7563;
cout << "Reverse a number:" << reverse(c) << "\n";
 
//palindrome
int g = 545;
cout << "Palindrome:" << isPalindrome(g) << endl;

/*Modulo Arithmetics
range int 32 bit = ans % 10^9 + 7(prime no and *prevent int overflow)
x % n = range of remainder (0,..,n-1)  100 % 3 = range (0,1,2) exist b/w range
(x+y)% m = x%m + y%m , (x-y)%m = x%m - y%m , (x.y)% m = x%m . y%m
((x%m)%m)%m....= (x%m)*/
  return 0;

}