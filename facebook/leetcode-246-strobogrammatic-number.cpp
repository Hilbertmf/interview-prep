// solved
// https://leetcode.com/problems/strobogrammatic-number/
// https://leetcode.ca/all/246.html
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

unordered_map <char, char> rotatedChars ({{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}});

// time: O(n)
// space: O(n)
bool isStrobogrammatic(string s) {
	string rotated = s;
	

	for(int i = 0; i < rotated.size(); i++) {
		if(rotatedChars.find(rotated[i]) == rotatedChars.end()) return false;
		rotated[i] = rotatedChars[rotated[i]];
	}

	reverse(rotated.begin(), rotated.end());
	return s == rotated;
}

// time: O(n)
// space: O(1)
bool isStrobogrammaticImproved(string s) {
	for(int i = 0, j = s.size()-1; i < s.size() && j >= 0 && i < j;
	 i++, j--) {
		 if(rotatedChars.find(s[i]) == rotatedChars.end() || s[i] != rotatedChars[s[j]]) return false;
	}

	if(s.size() % 2 != 0) {
		// mid must be the same after rotation
		return  s[s.size()/2] == rotatedChars[s[s.size()/2]];
	}
	return true;
}

int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while(t--) {
		string s;
		std::cin >> s;

		if(isStrobogrammatic(s)) std::cout << "true" << std::endl;
		else std::cout << "false" << std::endl;
	}
	
	return 0; 
}
/*
0 1 2 3 4 5 6 7 8 9
0 1 5 x x 2 9 x 8 6
time: O(n)
space: O(n)
case1:
in: "69" => 69
out: true

case2:
in: "88" => 88
out: true

case3:
in: "609" => 609
out: true

in: "33"
1 <= str.size <= 10⁴

*/