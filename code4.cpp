/* POINTERS:-Special variable that store address of other pointer
ADDRESS:-HexaDecimal {123456789abcdef}
ALIAS:-Different names to access the same memory location
& uses:- BITWISE OR, ADDRESS OF OPERAND, ALIAS
* uses:-MULTIPLY, DEREFERANCE*/
#include<iostream>
using namespace std;

void changeA1(int a){ //PASS BY VAL
  a=20;
}

// void changeA2(int* q) //PASS BY REFERENCE using pointers
// {           
//   *q=30;                                                                     
// }

//OR BY references(ALIAS):-
void changeA2(int &b){ //(store the add of a) pass the argument as value of a
    b=30; 
} 

int main(){
  int a=10;
  int* ptr=&a; 
  int** ptr2= &ptr;
  int* p=NULL; //Otherwise, Garbage value will be stored


  cout << ptr << endl; // ADDRESS OF a
  cout << &a << endl;
  cout << &ptr << endl; //ADDRESS OF POINTER
  cout << ptr2 << endl; //PARENT POINTER:-Stores add of pointer
  cout << *(ptr) << endl; // Dereference operator
  cout << *(&a) << endl;  //val of a
  cout << *(ptr2) << endl;// return add of var
  cout << **(ptr2) << endl; //double defer  var value

 changeA1(a);
 cout << "inside main fun: "<< a << endl;// VAL DOESN'T CHANGE

 changeA2(a); 
 cout << "inside main fun: "<< a << endl;// CHANGED

 int arr[]={1,2,3,4,5};
 cout << *arr << endl; // first value of arr 1
 cout << *(arr+2)<< endl;//3 contigous alloc so
 cout << *(arr+3)<< endl;//4
 int c=15;
 //arr = &a;  ARRAY POINTERS ARE CONSTANT POINTER if its change array elem add ll be lost
 
 //POINTER ARITHMETIC
 //INC(++) & DEC(--)
 int s = 10;
 int* w = &s;
 cout << w << endl;
 w++; // BYTE of memory of datatype is incremented NOT VAL 
 cout << w << endl;// int type so inc by 4bytes of memory
 w--;
 cout << w << endl;

 //ADD / SUB
 cout << w+3 << endl;// adds 3 int =12B (4*3) bytes of memory
 cout << w-4 << endl;// subs 4 int = 16B (4*4) bytes of memory

 //SUBSTRACT POINTER WITH POINTER
 //cannot add two pointers
 int* p1; //100
 int* p2=p1 + 2; //100+2*4B=108
 cout << p2 - p1 << endl;//(int)p2-(int)p1 -> 108B-100B=8B (2int) ans=2

 cout << ( p2 > p1) << endl;//RELATIONAL OPER :-{<, >, <=, >=, !=,==}

  return 0;
}

