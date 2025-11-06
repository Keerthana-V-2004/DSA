// TOP VIEW /BOTTOM VIEW OF THE TREE-O(nlogn) LEVEL ORDER IS USED-O(n) MAP O(logn) Horizontal distance(HD) => root/node(d) left(d-1)  right(d+1)
// use map(not unordered map) to find distinct HD 
// which are lies in the same horizontal line 
#include<iostream>
#include<vector>
#include<map>
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

void topView(Node* root) {  
  queue<pair<Node*,int>> q; 
  map<int,int> m;
  q.push({root,0});  //{node,HD}         
  
  while(q.size() >  0) {
    Node* curr = q.front().first; //in the queue node
    int currHD = q.front().second; //HD
    q.pop();

    if(m.find(currHD) == m.end()) { // if there is no same HD then only we can find the first and unique top view of the tree
      m[currHD] = curr->data;
    }

    if(curr->left != NULL) {
      q.push({curr->left, currHD-1});
    }
    if(curr->right != NULL) {
      q.push({curr->right, currHD+1});
    }
  }
  cout << "Top view of the tree: " ;
  for(auto it : m) {
    cout << it.second << " ";
  }
  cout << endl;
}

void bottomView(Node* root) {  
  queue<pair<Node*,int>> q; //{node,HD}  use map(not unordered map) to find distinct HD 
  map<int,int> m;
  q.push({root,0});                //which are lies in the same horizontal line 
  
  while(q.size() >  0) {
    Node* curr = q.front().first; //in the queue node
    int currHD = q.front().second; //HD
    q.pop();

    m[currHD] = curr->data;

    if(curr->left != NULL) {
      q.push({curr->left, currHD-1});
    }
    if(curr->right != NULL) {
      q.push({curr->right, currHD+1});
    }
  }
  cout << "Bottom view of the tree: " ;
  for(auto it : m) {
    cout << it.second << " ";
  }
  cout << endl;
}

void KthLevel(Node* root, int K) {
  if(root == NULL) {
    return;
  }

  if(K == 1) {          //when k==1 we reached the kth level in tree
    cout << root->data << " ";
    return;
  }

  KthLevel(root->left, K-1);
  KthLevel(root->right, K-1);
}
int main() {
  vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
  Node* root = buildTree(preorder);

  topView(root);
  bottomView(root);

  cout << "Kth level of tree :" ;
  KthLevel(root,3);
}