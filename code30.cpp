//LINKEDLIST - REVERSE A LINKED LIST
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

Node* reverseList(Node* head){
  Node* prev =NULL;
  Node* curr =head;
  Node* next =NULL;

  while (curr != NULL){
    next = curr->next;
    curr->next=prev;
    prev = curr;
    curr = next;
  }
  return prev;  // head of the reversed list
}

int main(){
  int n;
  cout << "Enter the number of elements:" << " ";
  cin >> n;
  Node* head = createList(n);
  
  cout << "Original list:" ;
  printList(head);

  head = reverseList(head);

  cout << "Reversed list:" ;
  printList(head);
  
} 