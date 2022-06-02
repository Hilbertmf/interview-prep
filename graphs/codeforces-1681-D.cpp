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

int bfs(long long start, int target, unordered_set<long long>& visited) {
    queue<pair<long long, int>> q;
    q.push({start, 0});
    while(!q.empty()) {
        long long curr = q.front().first;
        int level = q.front().second;
        q.pop();

        if(visited.find(curr) == visited.end()) { // not visited
            visited.insert(curr);
            int length = ceil(log10(curr));
            if(curr == (long long)pow(10, length))
                length++;
            
            if(length == target) {
                return level;
            }
            
            long long pos = 1;
            vector<int> digits;
            digits.reserve(length);

            while(curr >= pos) {
                int digit = (curr / pos) % 10;
                if(digit > 0) digits.push_back(digit);
                pos *= 10;
            }

            for(const auto &digit : digits) {
                long long child = curr * digit;
                if(visited.find(child) != visited.end())
                    continue;
                q.push({child, level + 1});
            }
            
        }

    }
    return -1;
}

int main() { 
    FASTIO;
    int n;
    long long x;
    cin >> n >> x;
    unordered_set<long long> visited;

    cout << bfs(x, n, visited) << "\n";
    
    return 0; 
}
