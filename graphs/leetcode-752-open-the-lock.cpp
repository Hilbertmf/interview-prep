// accepted
// https://leetcode.com/problems/open-the-lock
class Solution {
public:
    int bfs(string start, unordered_set<string>& deadsets, string target) {
        unordered_set<string> visited;
        visited.reserve(10000);
        queue<pair<string, int>> q;
        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            string curr = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(curr == target) {
                return dist;
            }
            if(deadsets.find(curr) != deadsets.end())
                continue;
            // neighbors
            for(int i = 0; i < 4; ++i) {
                string tmp = curr;
                tmp[i] += 1;
                if(tmp[i] > '9') tmp[i] = '0';
                if(visited.find(tmp) == visited.end()) {
                    visited.insert(tmp);
                    q.push({tmp, dist + 1});
                }
                tmp = curr;
                tmp[i] -= 1;
                if(tmp[i] < '0') tmp[i] = '9';
                if(visited.find(tmp) == visited.end()) {
                    visited.insert(tmp);
                    q.push({tmp, dist + 1});
                }
            }
        }
        return -1;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadsets(deadends.begin(), deadends.end());
        return bfs("0000", deadsets, target);
    }
};