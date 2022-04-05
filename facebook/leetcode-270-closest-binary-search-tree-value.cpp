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
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/** 
time: O(h), h = height of the tree, which == logn if tree is balanced
space: O(1)
target = 17

diffs:  16,7,2,3, 5, 8, 13
       [1,10,15,20,22,25,30]
     16
   /   \
  10     25
 / \     /  \
1   15   22   30
*/

void traverse(TreeNode* root, int &closestNodeVal, int target) {
	if(root == nullptr) return;

	if(root->val > target) traverse(root->left, closestNodeVal, target);

	if( abs(root->val - target) < abs(closestNodeVal - target) ) {
		closestNodeVal = root->val;
		if(root->val == target) return;
	}
	
	if(root->val < target) traverse(root->right, closestNodeVal, target);
	return;
}

int closestToTarget(TreeNode* root, int target) {
	int closestNodeVal = root->val;

	traverse(root, closestNodeVal, target);
	return closestNodeVal;
}

int main() { 
	FASTIO;
	
	
	return 0; 
}
