/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// time: O(num of nodes * num of neighbors)
// space: O(graph size)
class Solution {
public:
    void dfs(Node* node, unordered_map<Node*, Node*>& oldToNew) {
        if(node == nullptr || oldToNew.find(node) != oldToNew.end()) return;
        
        Node* tmp = new Node();
        tmp->val = node->val;
        oldToNew[node] = tmp;
        
        for(auto& n: node->neighbors) {
            dfs(n, oldToNew);
        }
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldToNew;
        dfs(node, oldToNew);
        
        for(const auto& kvp : oldToNew) {
            Node* old = kvp.first;
            Node* newNode = kvp.second;
            vector<Node*> newNeighbors;
            for(const auto& oldNeighbor : old->neighbors) {
                newNeighbors.push_back(oldToNew[oldNeighbor]);
            }
            newNode->neighbors = newNeighbors;
        }
        
        return oldToNew[node];
    }
};
