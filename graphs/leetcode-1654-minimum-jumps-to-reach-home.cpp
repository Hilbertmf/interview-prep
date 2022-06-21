// wrong answer
// https://leetcode.com/problems/minimum-jumps-to-reach-home/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct state {
        int pos;
        int jumps;
        char prevJump;
    };
    
    int minimumJumps(vector<int>& forbidden, int posRight, int posLeft, int target) {
        
        int pos = 0;
        unordered_set<int> forbiddenSet(forbidden.begin(), forbidden.end());
        unordered_set<int> visited;
        visited.reserve(target + posRight);
        queue<state> q;
        q.push((state){pos, 0, '.'});
        visited.insert(0);
        int count = 0;

        while (!q.empty()) {
            count++;

            int curr = q.front().pos;
            int jumps = q.front().jumps;
            char prevJump = q.front().prevJump;
            q.pop();
            cout << "curr: " << curr << "\n";

            if(curr == target) {
                cout << "num of iterations: " << count << "\n";
                return jumps;
            }

            // neighbors:
            // right:
            if(visited.find(curr + posRight) == visited.end() &&
            forbiddenSet.find(curr + posRight) == forbiddenSet.end()) {
                visited.insert(curr + posRight);
                q.push((state){curr + posRight, jumps + 1, 'r'});
            }

            // left:
            if(curr - posLeft >= 0 && prevJump != 'l' && visited.find(curr - posLeft) == visited.end() &&
            forbiddenSet.find(curr - posLeft) == forbiddenSet.end()) {
                visited.insert(curr - posLeft);
                q.push((state){curr - posLeft, jumps + 1, 'l'});
            }

        }

        return -1;
    }
};