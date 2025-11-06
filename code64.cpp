//LCA 236-LEETCODE - LOWEST COMMON ANCESTOR
//p,q both are having the same nearer ancestor 
//both are ancestors of themself also
//1.if p,q both are at root left and right subtree => root is gonna ancestor of both
//2.if p,q are at the left subtree => same recursion is applied it will return the both p,q then only it is considered as a ancestor otherwise it maybe return one Null from left/rgt and p/q from node 
//3.if p,q are at the right subtree =>it will also check for the values returned if both p,q are returned thn that is considered as ancestor
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

static int idx = -1;
Node* buildTree(vector<int> preorder) {
  idx++;

  if(preorder[idx] == -1) {
    return NULL;
  }

  Node* root = new Node(preorder[idx]);
  root->left = buildTree(preorder); //LEFT
  root->right = buildTree(preorder); //Right

  return root;

}

Node* lca(Node* root, Node* p,Node* q){
  if(root == NULL) return NULL;

  if(root->data == p->data || root->data == p->data) return root;

  Node* leftLCA = lca(root->left, p, q);
  Node* rightLCA = lca(root->right,p , q);

  if(leftLCA && rightLCA) return root;
  else if(!leftLCA) return leftLCA;
  else return rightLCA;
}
int main() {

}