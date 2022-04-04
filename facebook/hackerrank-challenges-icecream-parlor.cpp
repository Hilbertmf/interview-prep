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


int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while(t--) {
		int money, numFlavors;
		vector<int> ans(2, 0);
		unordered_multimap<int, int> map;

		std::cin >> money >> numFlavors;
		vector<int> costs(numFlavors);
		
		for(int i = 0; i < numFlavors; i++) {
			std::cin >> costs[i];
		}

		for(int i = 0; i < numFlavors; i++) {
			map.insert(make_pair(costs[i], i));
		}

		for(int i = 0; i < numFlavors && ans[0] == 0; i++) {
			int complement = money - costs[i];
			
			if(costs[i]*2 == money) { // edge case
				if(map.count(costs[i]) > 1) {
					auto range = map.equal_range(complement);
					auto it = range.first;
					int idx1, idx2;
					idx1 = it->second + 1;
					idx2 = std::next(it)->second + 1;
					ans[0] = min(idx1, idx2);
					ans[1] = max(idx1, idx2);
				}
			}
			else if(map.find(complement) != map.end()) {
				ans[0] = i+1;
				ans[1] = map.find(complement)->second + 1;
			}
    }

		std::cout << ans[0] << " " << ans[1] << std::endl;		
	}
	return 0; 
}
