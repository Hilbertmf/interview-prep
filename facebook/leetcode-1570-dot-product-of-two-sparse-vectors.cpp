// solved
// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/
// https://leetcode.ca/all/1570.html
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

class SparseVector {
  public:
  vector<int> nums;

  SparseVector() {}
  SparseVector(vector<int> vec) {nums = vec;}

	int dotProduct(SparseVector v2) {
		int sum = 0;
		vector<int> nums2 = v2.nums;

		for(int i = 0; i < nums.size(); i++) {
			sum += nums[i] * nums2[i];
		}

		return sum;
	}

};

int main() { 
	FASTIO;
	int n;
	std::cin >> n;

	vector<int> nums1(n), nums2(n);

	for(int i = 0; i < n; i++) {
		std::cin >> nums1[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> nums2[i];
	}
	
	SparseVector sv1(nums1);
	SparseVector sv2(nums2);

	std::cout << "v1.dotProduct(v2) = " << sv1.dotProduct(sv2) << std::endl;

	return 0; 
}


/*
time: O(n)
space: O(1)
ex1:
in:
nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
out:
8

ex2:
in:
nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
out:
0

ex3:
in:
nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
out:
6
*/