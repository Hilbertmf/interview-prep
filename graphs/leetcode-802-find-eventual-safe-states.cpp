// accepted
// https://leetcode.com/problems/find-eventual-safe-states
// first detect all cycles and add them to cycleNodes
// then get all ancestrals of each node in cycleNodes and
// mark them as unsafe
// answer are the nodes that remain
class Solution {
public:
    void traverseParents(int node, vector<vector<int>>& graph, vector<vector<int>>& parents,
    unordered_set<int>& cycleNodes) {

        for(auto &parent : parents[node]) {
            if(cycleNodes.find(parent) == cycleNodes.end()) {
                cycleNodes.insert(parent);
                traverseParents(parent, graph, parents, cycleNodes);
            }
        }
    }

    void detectCycle(int node, vector<vector<int>>& graph, vector<vector<int>>& parents,
    vector<int>& state, unordered_set<int>& cycleNodes) {
        state[node] = 1; // visiting

        for(auto &neighbor : graph[node]) {
            if(state[neighbor] == 0) {
                detectCycle(neighbor, graph, parents, state, cycleNodes);
            }
            else if(state[neighbor] == 1) { // cycle
                for(int i = 0; i < state.size(); ++i) {
                    if(state[i] == 1) {
                        cycleNodes.insert(i);
                        traverseParents(i, graph, parents, cycleNodes);
                    }
                }
            }
        }

        state[node] = 2; // visited
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> parents(graph.size());
        vector<int> state(graph.size());
        unordered_set<int> cycleNodes;
        cycleNodes.reserve(graph.size());

        for(int i = 0; i < graph.size(); ++i) {
            for(auto &neighbor : graph[i]) {
                parents[neighbor].push_back(i);
            }
        }

        for(int i = 0; i < graph.size(); ++i) {
            if(state[i] == 0) {
                detectCycle(i, graph, parents, state, cycleNodes);
            }
        }

        vector<int> safeNodes;
        for(int i = 0; i < graph.size(); ++i) {
            if(cycleNodes.find(i) == cycleNodes.end())
                safeNodes.push_back(i);
        }
        
        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};