// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


// tried using map, but not faster!!!

class Solution {
public:
    int maxp;

    int depth(TreeNode* root) {
      if (!root)
          return 0;
      int l = depth(root->left);
      int r = depth(root->right);
      maxp = max(maxp, l + r + 1);
      return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
      maxp = 0;
      if (!root)
        return maxp;
      depth(root);
      return maxp - 1;
    }
};

 
 // print it by level
ostream& operator<<(ostream& os, TreeNode* tr) {
  queue<TreeNode*> q;
  bool first = true;
  os << "[";
  if (tr) q.push(tr);
  while (!q.empty()) {
    int nodeCount = q.size();
    while (nodeCount > 0) {
      TreeNode* tp = q.front();
      q.pop();
      if (first) {
        os << tp->val;
        first = false;
      } else {
        os << "," << tp->val;
      }
      if (tp->left) q.push(tp->left);
      if (tp->right) q.push(tp->right);
      --nodeCount;
    }
  }
  os << "]";
  return os;
}

/*
          1
         / \
        2   3
       / \     
      4   5  
           \
            6
             \
              7
               \
                8
                 \
                  9

*/
int main() {
  Solution S;

  TreeNode *t1 = new TreeNode(1);
  t1->left = new TreeNode(2);
  
  // cout << "2?" << S.diameterOfBinaryTree(t1) << endl;

  t1->right = new TreeNode(3);

  cout << "2?" << S.diameterOfBinaryTree(t1) << endl;

  t1->left->left = new TreeNode(4);
  t1->left->right = new TreeNode(5);

  cout << "3?" << S.diameterOfBinaryTree(t1) << endl;

  t1->left->right->right = new TreeNode(6);
  t1->left->right->right->right = new TreeNode(7);
  t1->left->right->right->right->right = new TreeNode(8);
  t1->left->right->right->right->right->right = new TreeNode(9);

  cout << "7?" << S.diameterOfBinaryTree(t1) << endl;

  std::cout << "Hello World!\n";
}
