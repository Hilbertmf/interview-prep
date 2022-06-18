#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<int> nodesWithinCycles;
    int cycleEnd, cycleStart;
    // bool leaf(int node, vector<vector<int>>& graph) {
    //     return graph[node].size() == 0;
    // }

    bool hasCycle(int node, vector<int>& parents, vector<vector<int>>& graph,
        vector<int>& state) {
            state[node] = 1; // visiting

            for(auto neighbor : graph[node]) {
                if(state[neighbor] == 0) { // unvisited
                    parents[neighbor] = node;
                    if(hasCycle(neighbor, parents, graph, state))
                        return true;
                }
                else if(state[neighbor] == 1) { // found cycle
                    cycleEnd = node;
                    cycleStart = neighbor;
                    return true;
                }
            }
        
        state[node] = 2; // mark as visited
        return false;
    }


    void detectCycles(int node, vector<int>& parents, vector<vector<int>>& graph,
     vector<bool>& visited) {
        bool isSafe = true;

        for(auto neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                parents[neighbor] = node;
                detectCycles(neighbor, parents, graph, visited);
            }
            else { // if has been visited then cycle
                nodesWithinCycles.insert(node);
            }
            // else if(neighbor != parent) {
            // }
        }

        // if(isSafe)
        //     safeNodes.push_back(node);

    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size());
        vector<int> safeNodes;
        vector<int> parents(graph.size(), -1);
        safeNodes.reserve(graph.size());
        vector<int>& state(graph.size(), 0); // 0 unvisited, 1 visiting, 2 visited

        for(int i = 0; i < graph.size(); ++i) {
            if(!visited[i]) {
                visited[i] = true;
                detectCycles(i, parents, graph, visited);
                // detectCycles(i, graph, visited, safeNodes);
            }
        }

        vector<int> paths;
        for(const auto &node : nodesWithinCycles) {
            int currNode = node;
            while(currNode < parents.size() && parents[currNode] != -1) {
                paths.push_back(parents[currNode]);
                // nodesWithinCycles.pu(parents[currNode]);
                currNode = parents[currNode];
            }
        }

        for(const auto &node : paths) {
            nodesWithinCycles.insert(node);
        }

        for(const auto &node : nodesWithinCycles) {
            cout << "node: " << node << "\n";
        }
        
        for(int node = 0; node < graph.size(); ++node) {
            if(nodesWithinCycles.find(node) == nodesWithinCycles.end())
                safeNodes.push_back(node);
        }
        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};