//IMPLEMENT LRU CACHE - USING DLL AND MAP
//TC- O(1)
#include<iostream>
#include<unordered_map>
using namespace std;

class LruCache {
public:
  class Node {
  public:
   int key , val;
   Node* prev;
   Node* next;

   Node(int k,int v) {
    key = k;
    val = v;
    prev = next = NULL;
   }
};

Node* head = new Node(-1,-1);
Node* tail = new Node(-1,-1);

unordered_map <int,Node*> m; 
int limit;

  void addNode(Node* newNode) {
    Node* oldNext = head->next; //tail

    head->next = newNode;
    oldNext->prev = newNode; //tail

    newNode->next = oldNext;
    newNode->prev = head;
  }

  void delNode(Node* oldNode) {
    Node* oldprev = oldNode->prev;
    Node* oldnext = oldNode->next;

    oldnext->prev = oldprev;
    oldprev->next = oldnext;

  }

  LruCache(int capacity) {
    limit = capacity;
    head->next = tail;
    tail->prev = head;

  }

  int get(int key) {
    if(m.find(key) == m.end()) {
      return -1;
    }

    Node* ansNode = m[key];
    int ans = ansNode->val;

    m.erase(key);
    delNode(ansNode);

    addNode(ansNode);
    m[key] = ansNode;

  return ans;
  }

  void put(int key, int val) {
    if(m.find(key) != m.end()) {
      Node* oldnode = m[key];
      delNode(oldnode);
      m.erase(key);
    }

    if(m.size() == limit) {
      //delete the LRU node at the tail prev
      m.erase(tail->prev->key);
      delNode(tail->prev);
    }

    Node* newNode = new Node(key,val);
    addNode(newNode);
    m[key] = newNode;

  }
};

int main() {
  LruCache obj(2);

  obj.put(1,1);
  obj.put(2,2);

  obj.get(1);
  cout << "get 1:" << obj.get(1) << endl;

  obj.put(3,3);

  cout << "get 2:" <<obj.get(2) << endl;

  obj.put(4,4);

  obj.get(1);
  cout << "get 1:" <<obj.get(1) << endl;

  obj.get(3);
  cout << "get 1:" <<obj.get(3) << endl;

  obj.get(4);
  cout << "get 1:" <<obj.get(4) << endl;

}

