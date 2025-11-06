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

Node* hasCycle(Node* head){
  Node* slow = head;
  Node* fast = head;
  bool isCycle = false;

  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){   // 4 here
      isCycle = true;
      break;
    }
  }
  if(!isCycle) return NULL;  // if there is no cycle

  slow = head;     //again at start node of the list

  Node* prev = NULL;
  while(slow != fast){
    slow = slow->next;    //+1
    prev = fast;          // this is pointing to 4 here as slow != fast becm 5 
    fast = fast->next;    //+1
  }
  prev->next = NULL; // remove cycle , 5 is next point to null instead of 3
  return slow;       // Start node of the cycle
}

int main(){
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  
  //Create cycle :- 5 to 3
  head->next->next->next->next->next = head->next->next ;
  
  Node* m = hasCycle(head);

  cout << "Start node of cycle: "<< m->data << endl;

} 
