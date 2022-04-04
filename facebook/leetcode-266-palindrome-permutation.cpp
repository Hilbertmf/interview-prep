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

bool canFormPalindrome(string s) {
	unordered_map<char, int> chars;

	for(char &c : s) {
		chars[c]++;
	}
	int numOddChars = 0;
	for(auto it = chars.begin(); it != chars.end(); it++) {
		if(it->second % 2 != 0) {
			numOddChars++;
		}
	}

	return numOddChars <= 1;
}


int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		string s;
		std::cin >> s;

		if(canFormPalindrome(s)) std::cout << "true" << std::endl;
		else std::cout << "false" << std::endl;
	}
	
	
	return 0; 
}
