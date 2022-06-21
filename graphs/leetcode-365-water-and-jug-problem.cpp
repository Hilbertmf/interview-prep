// time limit exceeded (need optimization)
// https://leetcode.com/problems/water-and-jug-problem/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void add(queue<string>& q, string& tmp, unordered_set<string>& visited) {
        if(visited.find(tmp) == visited.end()) {
            visited.insert(tmp);
            q.push(tmp);
        }
    }

    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        unordered_set<string> visited;
        visited.reserve(max(abs(targetCapacity - jug1Capacity),
        abs(targetCapacity - jug2Capacity)) * 10);

        queue<string> q;
        // sources:
        q.push("0,0");
        visited.insert("0,0");
        q.push(to_string(jug1Capacity) + ",0");
        visited.insert(to_string(jug1Capacity) + ",0");
        q.push("0," + to_string(jug2Capacity));
        visited.insert("0," + to_string(jug2Capacity));
        q.push(to_string(jug1Capacity) + "," + to_string(jug2Capacity));
        visited.insert(to_string(jug1Capacity) + "," + to_string(jug2Capacity));

        while (!q.empty()) {
            string str = q.front();
            q.pop();
            string s1 = str.substr(0, str.find(','));
            string s2 = str.substr(str.find(',') + 1);
            int c1 = stoi(s1, nullptr);
            int c2 = stoi(s2, nullptr);

            // base case
            if(c1 == targetCapacity || c2 == targetCapacity || c1 + c2 == targetCapacity) {
                return true;
            }

            // neighbors:
            // empty any:
            string tmp;
            tmp = s1 + ",0";
            add(q, tmp, visited);
            tmp = "0," + s2;
            add(q, tmp, visited);
            // fill any jug:
            tmp = to_string(jug1Capacity) + "," + s2;
            add(q, tmp, visited);
            tmp = s1 + "," + to_string(jug2Capacity);
            add(q, tmp, visited);
            // pour from one to another
            if(c1 + c2 > jug2Capacity) {
                tmp = to_string(c1 - (jug2Capacity - c2)) + "," + to_string(jug2Capacity);
                add(q, tmp, visited);
            }
            else {
                tmp = "0," + to_string(c1 + c2);
                add(q, tmp, visited);
            }

            if(c2 + c1 > jug1Capacity) {
                tmp = to_string(jug1Capacity) + "," + to_string(c2 - (jug1Capacity - c1));
                add(q, tmp, visited);
            }
            else {
                tmp = to_string(c2 + c1) + ",0";
                add(q, tmp, visited);
            }
        }

        return false;
    }
};