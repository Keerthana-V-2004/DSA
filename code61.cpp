//BINARY TREES - O(n) - all are linear TC
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
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

void preOrder(Node* root) { //root left right
  if(root == NULL) {
    return;
  }
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node* root) { // left root right
  if(root == NULL) {
    return;
  }
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void postOrder(Node* root) { // left right root
  if(root == NULL) {
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

void levelOrder(Node* root) {
  queue<Node*> q;

  q.push(root);
  q.push(NULL);

  while(q.size() > 0) {
    Node* curr = q.front();
    q.pop();

    if(curr == NULL) {
      if(!q.empty()) {
        cout << endl;
        q.push(NULL);
        continue;
      } else {
        break;
      }
    }

    cout << curr->data << " ";

    if(curr->left != NULL) {
      q.push(curr->left);
    }
    if(curr->right != NULL) {
      q.push(curr->right);
    }
  }
  cout << endl;
}

int ans = 0;
int height(Node* root) {
  if(root == NULL) {
    return 0;
  }

  int leftHeight = height(root->left);
  int rightHeight = height(root->right);
  ans = max(ans, leftHeight+rightHeight);
  return max(leftHeight , rightHeight) + 1;
}

int diameterOfBT(Node* root) { //O(n^2) 
  //use of height fun we can fix it by optimization in the height fun itself no need to call again to calculate same heights here again
  //here just call => height(root); return ans;
  if(root == NULL) return 0;

  int leftDia = diameterOfBT(root->left);
  int rightDia = diameterOfBT(root->right);
  int currDia = height(root->left) + height(root->right);

  return max(currDia, max(leftDia, rightDia));
}

int count(Node* root) {
  if(root == NULL) {
    return 0;
  }

  int leftCount = count(root->left);
  int rightCount = count(root->right);
  return leftCount + rightCount + 1;
}

int sumOfNodes(Node* root) {
  if(root == NULL) {
    return 0;
  }

  int leftSum = sumOfNodes(root->left);
  int rightSum = sumOfNodes(root->right);
  return leftSum + rightSum + root->data;
}

int sumTree(Node* root) {
  if(root == NULL) return 0;

  int leftSum = sumTree(root->left);
  int rgtSum = sumTree(root->right);

  root->data +=(leftSum + rgtSum);
  return root->data;
}

vector<string> binaryTreePaths(Node* root, string path,vector<string> &ans) {
  if(root->left == NULL && root->right == NULL) {
    ans.push_back(path);
    return ans;
  }
  if(root->left) 
    return binaryTreePaths(root->left,path+"->"+to_string(root->left->data),ans);
  
  if(root->right) 
    return binaryTreePaths(root->right,path+"->"+to_string(root->right->data),ans);
  
}

int main() {
  vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
  Node* root = buildTree(preorder);

  cout << root->data << " " << root->left->data << " " << root->right->data << "\n";

  preOrder(root);
  cout << "\n";
  inOrder(root);
  cout << "\n";
  postOrder(root);
  cout << "\n";
  levelOrder(root);

  int hgt = height(root);
  cout << "height of the tree :" << hgt  << "\n";

  int diameter = diameterOfBT(root);
  cout << "Diameter of tree :" << diameter << "\n";

  int cnt  = count(root);
  cout << "Count of Nodes : " << cnt << "\n"; 

  int sum = sumOfNodes(root);
  cout << "Sum of Nodes :" << sum << "\n";

  cout << "Before sumTree : "; 
  preOrder(root);
  cout << "\n";

  sumTree(root);

  cout << "After sumTree : "; 
  preOrder(root);
  cout << "\n";

  int path = root->data;
  vector<string> ans;
  vector<string> paths = binaryTreePaths(root,to_string(path),ans);
  for(string path : paths){
    cout << path << "\n";
  }
    
  return 0;
}