//LEETCODE 24 - SWAP NODES IN PAIRS - TC-O(n) SC-O(1)
//LIST - [ 1     ,2       ,3      ,4   ,NULL]
//  prev   first , second , third
//   [ 2    ,1       ,3      ,4       ,NULL]
//          prev     ,first  ,second  ,third

//in place so no need to copy the remaining node if there is no pair for node

#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;

  Node(int val){
    data = val;
    next = NULL;
  }
};

Node* createList(int n){
  if(n <= 0) return NULL;

  cout << "Enter " << n << " elements: ";
  int val;
  cin >> val;
  Node* head = new Node(val);
  Node* temp = head;

  for(int i=1; i<n ;i++){
    cin >> val;
    temp->next = new Node(val);
    temp = temp->next;
  }
  return head;
}

void printList(Node* head){
  Node* temp = head;
  while(temp != NULL){
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node* swapPairs(Node* head){
  if(head == NULL || head->next == NULL){
    return head;
  }
  Node* first = head;
  Node* sec = head->next;
  Node* prev = NULL;

  while(first != NULL && sec != NULL){
  Node* third = sec->next;

  sec->next = first;
  first->next = third;

  if(prev != NULL){
    prev->next = sec;
  } else {
    head = sec;  //after swap sec ele is first ele
  }

  //Update
  prev = first;
  first = third;
  if(third != NULL){  //if there is no more ele
    sec = third->next;  
  } else {
    sec = NULL;
  }
  }
  return head;
}

int main(){
  int n;
  cout << "Enter the number of elements:" << " ";
  cin >> n;
  Node* head = createList(n);
  
  cout << "Original list:" ;
  printList(head);

  Node* head1 = swapPairs(head);

  cout << "After swap :";
  printList(head1);
}