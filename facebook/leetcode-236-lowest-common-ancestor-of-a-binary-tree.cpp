// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
bool dfs(TreeNode *curr, TreeNode*& lca, TreeNode *p, TreeNode *q) {
		if(curr == nullptr) return false;

        bool isLeaf = curr->left == nullptr && curr->right == nullptr;
		if(isLeaf && (curr == p || curr == q)) return true;
        
	
		bool hasLeft = dfs(curr->left, lca, p, q);
		bool hasRight = dfs(curr->right, lca, p, q);
		bool hasLeftAndRight = hasLeft && hasRight;
		if(lca == nullptr &&
		( hasLeftAndRight || ( (curr == p || curr == q) && (hasLeft || hasRight) ) )) {
			lca = curr;
			return true;
		}
		
		return hasLeft || hasRight || curr == p || curr == q;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* lca = new TreeNode();
		lca = nullptr;
		bool hasLca = dfs(root, lca, p, q);
		return lca;
    }
};



// time: O(n)
// space: O(n)
class Solution {
public:
    bool dfs(TreeNode* node, int target, vector<TreeNode*>& parents) {
		if(node == nullptr) return false;

		bool isParent = false;
		if(node->val == target) {
			parents.push_back(node);
			return true;
		}
		if(dfs(node->left, target, parents) || dfs(node->right, target, parents)) {
			isParent = true;
			parents.push_back(node);
		}
		return isParent;
	}
	
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> parentsP;
		vector<TreeNode*> parentsQ;
		bool hasLCA;
		hasLCA = dfs(root, p->val, parentsP);
		hasLCA = dfs(root, q->val, parentsQ);
		TreeNode* lca = nullptr;
			
		for(int i = parentsP.size() - 1, j = parentsQ.size() - 1;
		i >= 0 && j >= 0 && lca == nullptr
		; --i, --j) {
			if(parentsP[i] != parentsQ[j]) {
				lca = parentsP[i + 1];
			}
		}
		
		if(lca == nullptr) { // get first node of smallest arr
			if(parentsP.size() < parentsQ.size()) 
				lca = parentsP[0];
			else
				lca = parentsQ[0];
		}
		return lca;
    }
};

/*
dfs from root till find target
    if target return true
    if child == true insert node in parents collection (vector)
*/

int main() { 
	FASTIO;
	
	
	return 0; 
}
