//MERGE TWO SORTED LIST - TC-O(n+m)
//Recursive is better than iterative
//return the head of the merged list

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

  cout << "Enter " << n << "nodes ";
  int val;
  cin >> val;
  Node* head = new Node(val);
  Node* temp = head;

  for(int i=1; i<n ; i++){
    cin >> val;
    temp->next = new Node(val);
    temp = temp->next;

  }
  return head;
}

void printList(Node* head){
  while(head != NULL){
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

Node* mergeTwoList(Node* head1 ,Node* head2){
  if(head1 == NULL || head2 == NULL){
    return head1 == NULL ? head2 : head1 ;
  }

  //case1
  if(head1->data <= head2->data){
    head1->next = mergeTwoList(head1->next , head2);
    return head1;
  } else {  //case2
    head2->next = mergeTwoList(head1 , head2->next);
    return head2;
  }
}

int main(){
  int n1,n2;

  cout << "Enter number of nodes in first list:";
  cin >> n1;
  Node* head1 = createList(n1);

  cout << "Enter number of nodes in second list:";
  cin >> n2;
  Node* head2 = createList(n2);

  cout << "First List: " ;
  printList(head1);

  cout << "Second List: " ;
  printList(head2);

  Node* ans = mergeTwoList(head1 , head2);
  cout << "First node of merged list" << ans->data << endl;
  
}