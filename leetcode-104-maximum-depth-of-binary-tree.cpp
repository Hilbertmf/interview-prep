#include <bits/stdc++.h>
using namespace std;

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
    int bfs(TreeNode* root) {

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int depth = 0;

        while (!q.empty()) {
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(node == nullptr) continue;

            depth = max(depth, level);
            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }
        return depth;
    }

    int dfsIterative(TreeNode* root) {
        int depth = 0;
        stack<pair<TreeNode*, int>> myStack;
        myStack.push({root, 1});

        while (!myStack.empty()) {
            auto node = myStack.top().first;
            int currDepth = myStack.top().second;
            myStack.pop();
            if(node == nullptr) continue;

            depth = max(depth, currDepth);
            myStack.push({node->right, currDepth + 1});
            myStack.push({node->left, currDepth + 1});
        }

        return depth;
    }

    int dfs(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }

    int maxDepth(TreeNode* root) {

        return bfs(root);
        // return dfs(root);
    }
};