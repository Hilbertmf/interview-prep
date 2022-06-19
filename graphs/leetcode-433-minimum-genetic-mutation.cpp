// accepted
// https://leetcode.com/problems/minimum-genetic-mutation/submissions/
class Solution {
public:
    int bfs(string start, string end, unordered_set<string>& bank) {
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            string curr = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(curr == end) {
                return dist;
            }

            // neighbors
            for(int i = 0; i < curr.size(); ++i) {
                string tmp = curr;
                tmp[i] = 'A';
                if(visited.find(tmp) == visited.end() && bank.find(tmp) != bank.end()) {
                    visited.insert(tmp);
                    q.push({tmp, dist + 1});
                }
                tmp[i] = 'C';
                if(visited.find(tmp) == visited.end() && bank.find(tmp) != bank.end()) {
                    visited.insert(tmp);
                    q.push({tmp, dist + 1});
                }
                tmp[i] = 'G';
                if(visited.find(tmp) == visited.end() && bank.find(tmp) != bank.end()) {
                    visited.insert(tmp);
                    q.push({tmp, dist + 1});
                }
                tmp[i] = 'T';
                if(visited.find(tmp) == visited.end() && bank.find(tmp) != bank.end()) {
                    visited.insert(tmp);
                    q.push({tmp, dist + 1});
                }
            }
        }

        return -1;
    }

    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());

        if(bankSet.find(end) == bankSet.end())
            return -1;

        return bfs(start, end, bankSet);
    }
};