// https://leetcode.ca/all/1216.html
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

/*
maybe:
unordered_map <pair<int,int>, bool> map;
*/ 


bool isPalindrome(string s, int i, int j, int k) {
	if(k < 0) {
		return false;
	}
	while(i < j) {
		if(s[i] != s[j]) {
			 return isPalindrome(s, i, j-1, k-1) ||
			 				isPalindrome(s, i+1, j, k-1);
		}
		i++;
		j--;
	}
	return true;
}

bool validKPalindrome(string s, int k) {
	int count = 0;
	int i = 0, j = s.size()-1;
	while(i < j) {
		if(s[i] != s[j]) {
			return isPalindrome(s, i, j-1, k-1) || // from i -> j-1
						 isPalindrome(s, i+1, j, k-1);// from i+1 -> j
		}
		i++;
		j--;
	}
	return true;
}

int main() { 
	FASTIO;
	string s;
	int k;
	std::cin >> s >> k;

	if(validKPalindrome(s, k)) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
	return 0; 
}
