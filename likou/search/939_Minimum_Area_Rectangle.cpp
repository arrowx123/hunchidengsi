// sort by column
class Solution {
public:
  int minAreaRect(vector<vector<int>> &points) {
    int n = points.size();
    map<int, vector<vector<int>>> myMap;
    for (int i = 0; i < n; i++) {
      myMap[points[i][0]].push_back(points[i]);
    }

    unordered_map<int, int> seen;
    int ans = INT_MAX;
    for (auto &v : myMap) {
      vector<vector<int>> &vec = v.second;
      int len = vec.size();

      for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
          int minY = min(vec[i][1], vec[j][1]);
          int maxY = max(vec[i][1], vec[j][1]);

          int mask = 40001 * minY + maxY;
          if (seen.count(mask)) {
            ans = min(ans, (vec[i][0] - seen[mask]) * (maxY - minY));
          }
          seen[mask] = vec[i][0];
        }
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};
