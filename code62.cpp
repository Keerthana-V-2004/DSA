//IDENTICAL TREE - SAME TREE
//SUBTREE OF ANOTHER TREE

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

class Tree {

public:

Node* buildTree(vector<int> preorder, int &idx) {
  idx++;

  if(preorder[idx] == -1) {
    return NULL;
  }

  Node* root = new Node(preorder[idx]);
  root->left = buildTree(preorder,idx); //LEFT
  root->right = buildTree(preorder,idx); //Right

  return root;
  }

  bool isSameTree(Node* p, Node* q) {
  if(!p && !q ) return true;
  if(!p || !q) return false;

  bool isLeftSame = isSameTree(p->left , q->left);
  bool isrightSame = isSameTree(p->right , q->right);

  return  (p->data == q->data) && isLeftSame && isrightSame  ;
  }

  bool isSubTree(Node* root, Node* subRoot) {
    if( subRoot == NULL) return true;
    if(root == NULL ) return false;
    
    if(isSameTree(root, subRoot)) {
      return true;
    }

    return isSubTree(root->left , subRoot)
          || isSubTree(root->right, subRoot);
  }

};


int main() {
  Tree t;
  int idx1 =-1 , idx2=-1,idx3=-1;
  vector<int> preorder1 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
  Node* root1 = t.buildTree(preorder1,idx1);
  vector<int> preorder2 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
  Node* root2 = t.buildTree(preorder2,idx2);
  cout << root1->data << "\n";

  vector<int> preorder3 = {3,4,-1,-1,5,-1,-1};
  Node* root3 = t.buildTree(preorder3,idx3);

  cout << root3->data << "\n";
  bool result = t.isSameTree(root1,root2);

  cout << "Is same :" << result << "\n";

  bool res = t.isSubTree(root2,root3);
  cout << "Is subtree : " << res << "\n";
  return 0;
}