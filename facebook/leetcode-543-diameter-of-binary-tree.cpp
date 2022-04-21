/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  
  int getHeight(TreeNode* root, int& longestPath) {
    if(root == nullptr) return -1;
    
    int leftHeight = getHeight(root->left, longestPath);
    int rightHeight = getHeight(root->right, longestPath);
    longestPath = max(longestPath, leftHeight + rightHeight + 1);
    
    return max(leftHeight, rightHeight) + 1;
  }
  
  int diameterOfBinaryTree(TreeNode* root) {
    int longestPath = -1e9;
    int height = getHeight(root, longestPath);
    
    return longestPath + 1;
  }
};
/*
time: O(n)
space: O(n)
>     1
     / \ 
   2    3
   /\ 
  4  5
*/