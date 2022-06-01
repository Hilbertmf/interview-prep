// time: O(1)
// space: O(1)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int star = 0;
        pair<int, int> edge1 = {edges[0][0], edges[0][1]};
        pair<int, int> edge2 = {edges[1][0], edges[1][1]};

        if(edge1.first == edge2.first) {
            star = edge1.first;
        }
        else if(edge1.first == edge2.second) {
            star = edge1.first;
        }
        else if(edge1.second == edge2.first) {
            star = edge1.second;
        }
        else {
            star = edge2.second;
        }

        return star;
    }
};