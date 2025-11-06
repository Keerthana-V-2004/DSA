//BUILT TREE FROM PREORDER AND INORDER
//preorder = [3,9,20,15,7] inorder =  [9, 3, 15, 20, 7]
//left : l to idx-1  rgt: idx+1 to r, l=0 inx       r=4
//preorder => root,left,rgt inorder=>left,root,rgt
//to identify the left and rgt in the pre use the root from pre in inorder
//here 3 is root => search for left ,rgt => inorder before 3-left 9 , aft 3-rgt 15,20,7
//again by pre 20 is root of rgt-subtree => left-15 and rgt-7

#include<iostream>
#include<vector>
#include<queue>

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

int maxWidthBT(Node* root) {
  queue<pair<Node* ,unsigned long long>> q;
  q.push({root,0});
  int maxWidth = 0;

  while (q.size() > 0)
  {
    int currLevelSize = q.size();
    unsigned long long stIdx = q.front().second;
    unsigned long long endIdx = q.back().second;

    maxWidth = max(maxWidth, int(endIdx-stIdx+1));

    for(int i=0 ; i<currLevelSize; i++){
      auto curr = q.front();
      q.pop();

      if(curr.first->left) {
         q.push({curr.first->left,curr.second*2+1});
      }

      if(curr.first->right) {
         q.push({curr.first->right,curr.second*2+2});
      }
    }
  }
  return maxWidth;

}

//Morris inorder traversel - Iterative traversal-inoder predecessor
//there is no way to backtrack in the iteration so we need to create temporary thread connection b/w root and right-leaf node in left-subtree and in right-subtree root and left-leaf
vector<int> inorderTraversal(Node* root) {
  vector<int> ans;
  Node* curr = root;

  while(curr != NULL) {
    if(curr->left == NULL) {
      ans.push_back(curr->data);
      curr = curr->right;
    } else {
      //find inorder predecessor
      Node* IP = curr->left;
      while(IP->right != NULL && IP->right != curr) {
        IP = IP->right;
      }
      if(IP->right == NULL){
        IP->right = curr;
        curr = curr->left;
      } else {
        IP->right = NULL; //destroy
        ans.push_back(curr->data);
        curr = curr->right;
      }
    }

  }
  return ans;
}

int main() {
  vector<int> preorder = {3,9,20,15,7};
  vector<int> inorder = {9,3,15,20,7};
  int preIdx = 0;
  Node* root = buildTree(preorder,inorder,preIdx,0,inorder.size()-1);
  cout << root->data << endl;

  int maxWidth = maxWidthBT(root);
  cout << maxWidth << endl;

  vector<int> inord = inorderTraversal(root);
  for(int ans : inord) {
    cout << ans  << " ";
  }
  return 0;
}