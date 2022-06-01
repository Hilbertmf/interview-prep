// https://leetcode.com/problems/minimum-cost-to-connect-sticks/
// time: O(nlogn)
// space: O(1)
int getMinCost(vector<int>& sticks) {
    sort(sticks.begin(), sticks.end());
    int stickLength = sticks[0];
    if(sticks.size() > 1)
        stickLength += sticks[1];
    int cost = stickLength;

    for(int i = 2; i < sticks.size(); ++i) {
        stickLength += sticks[i];
        cost += stickLength;
    }

    return cost;
}