//BUILT TREE FROM PREORDER AND INORDER
//preorder = [3,9,20,15,7] inorder =  [9, 3, 15, 20, 7]
//left : l to idx-1  rgt: idx+1 to r, l=0 inx       r=4
//preorder => root,left,rgt inorder=>left,root,rgt
//to identify the left and rgt in the pre use the root from pre in inorder
//here 3 is root => search for left ,rgt => inorder before 3-left 9 , aft 3-rgt 15,20,7
//again by pre 20 is root of rgt-subtree => left-15 and rgt-7

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

int search(vector<int>& inorder,int st, int rgt,int val) {
  for(int i=0; i<=rgt; i++) {
    if(inorder[i] == val) {
      return i;
    }
  }
  return -1; //we always going to get the root
}

static int preIdx = 0;
Node* buildTree(vector<int> &preorder,vector<int> &inorder,int& preIdx, int left, int rgt) {
  if(left > rgt) {
    return NULL;
  }

  Node* root = new Node(preorder[preIdx]);

  int inIdx = search(inorder,left,rgt,preorder[preIdx]);
  preIdx++;
  
  root->left = buildTree(preorder,inorder,preIdx,left,inIdx-1);
  root->right = buildTree(preorder,inorder,preIdx,inIdx+1,rgt);

  return root;

}

int main() {
  vector<int> preorder = {3,9,20,15,7};
  vector<int> inorder = {9,3,15,20,7};
  int preIdx = 0;
  Node* root = buildTree(preorder,inorder,preIdx,0,inorder.size()-1);
  cout << root->data << endl;
  return 0;
}