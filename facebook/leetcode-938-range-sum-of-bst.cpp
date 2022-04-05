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
  void traversal(TreeNode* root, int low, int high, int &sum) {
    if(root == nullptr) return;
    
    if(root->val > low)
      traversal(root->left, low, high, sum);
    if(root->val >= low && root->val <= high)
      sum += root->val;
    if(root->val < high)
      traversal(root->right, low, high, sum);
  }
  
  int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    traversal(root, low, high, sum);
    
    return sum;
  }
};
/* low=7, high=15
   10
   / \
  5   15
 / \   \
3   7   18

time:O(n)
space:O(nlogn)
*/

