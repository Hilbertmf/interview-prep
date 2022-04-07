// solved (AC)
// https://leetcode.com/problems/k-closest-points-to-origin/
double distToOrigin(vector<int>& v) {
  int x = v[0], y = v[1];
  return sqrt(x*x + y*y);
}
bool comp(vector<int>& a, vector<int>& b) {
  return distToOrigin(a) < distToOrigin(b);
}
class Solution {
public:
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

  std::sort(points.begin(), points.end(), comp);
  vector<vector<int>> KClosestPoints(k);
    
  for(int i = 0; i < k; i++) {
    KClosestPoints[i] = points[i];
  }
  
  return KClosestPoints;
  }
};