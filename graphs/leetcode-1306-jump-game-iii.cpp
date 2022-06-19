// accepted
// https://leetcode.com/problems/jump-game-iii
class Solution {
public:
    bool valid(int index, vector<int>& arr) {
        return index >= 0 && index < arr.size();
    }

    bool bfs(int start, vector<int>& arr) {
        queue<int> q;
        q.push(start);
        unordered_set<int> visited;
        visited.reserve(arr.size());

        while (!q.empty()) {
            int index = q.front();
            q.pop();
            if(valid(index, arr) && arr[index] == 0) {
                return true;
            }

            if(visited.find(index) != visited.end())
                continue;
            visited.insert(index);

            // neighbors
            if(valid(index, arr)) {
                q.push(index + arr[index]);
                q.push(index - arr[index]);
            }

        }

        return false;
    }
    
    bool canReach(vector<int>& arr, int start) {

        return bfs(start, arr);
    }
};