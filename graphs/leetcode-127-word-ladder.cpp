// accepted
// https://leetcode.com/problems/word-ladder
class Solution {
public:
    int bfs(string start, string end, unordered_set<string>& words) {
        queue<pair<string, int>> q;
        q.push({start, 1});
        unordered_set<string> visited;
        visited.insert(start);

        while (!q.empty()) {
            string curr = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(curr == end)
                return dist;

            // neighbors
            for(int i = 0; i < curr.size(); ++i) {
                string tmp = curr;
                
                for(int j = 0; j < 26; ++j) {
                    tmp[i] = 'a' + j;
                    if(visited.find(tmp) == visited.end() && words.find(tmp) != words.end()) {
                        visited.insert(tmp);
                        q.push({tmp, dist + 1});
                    }
                }
            }

        }

        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        return bfs(beginWord, endWord, wordSet);
    }
};