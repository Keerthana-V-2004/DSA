//LEETCODE - MIDDLE OF THE LINKED LIST
//EVEN - two nodes as middle (choose 2nd node as middle)  ODD- middle node
//BRUTE - 1.Size of LL 2.size/2 + 1 = ans of the middle node pos
//SLOW-FAST POINTER -TC_O(n) at the end fast pointer pointing to last node of list
//the slow pointer is at the middle of the list

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

Node* middleNode(Node* head){
  Node* slow = head;
  Node* fast = head;

  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}


int main(){
  int n;
  cout << "Enter the number of elements:" << " ";
  cin >> n;
  Node* head = createList(n);
  cout << "Linked list:";
  printList(head);
  
  Node* mid = middleNode(head);

  cout << "Middle node: "<< mid->data << endl;

} 