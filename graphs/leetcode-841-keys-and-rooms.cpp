// accepted
// https://leetcode.com/problems/keys-and-rooms/
class Solution {
public:
    void dfs(int room, vector<vector<int>>& rooms, unordered_set<int>& keys,
    vector<bool>& visited) {

        for(auto &key : rooms[room]) {
            keys.insert(key);
        }

        for(auto &roomKey : keys) {
            if(!visited[roomKey]) {
                visited[roomKey] = true;
                dfs(roomKey, rooms, keys, visited);
            }
        }

    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys;
        keys.reserve(rooms.size());
        vector<bool> visited(rooms.size());
        visited[0] = true;
        dfs(0, rooms, keys, visited);

        return find_if(visited.begin(), visited.end(),
            [](bool elem) {
                return !elem;
            }) == visited.end();
    }
};