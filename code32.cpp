//LEETCODE 141- DETECT AND REMOVE A CYCLE IN LINKED LIST
//1.Slow-fast pointer approach
//1.TRUE - if cycle is exists - at one point slow and fast both are 'll be at the same node
//2.False- if no cycle - fast will reach last node earlier

//If there is no loop
//distance b/w the slow and fast pointer is always 0,1,2,3...+1 in each move

//There is loop - 
#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;

  Node(int val){
    data = val;
    next = NULL;
  }
};

bool hasCycle(Node* head){
  Node* slow = head;
  Node* fast = head;

  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
      return true;
    }
  }
  return false;
}


int main(){
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  
  //Create cycle :- 5 to 3
  head->next->next->next->next->next = head->next->next ;
  
  bool m = hasCycle(head);

  cout << "Has cycle: "<< m << endl;

} 
