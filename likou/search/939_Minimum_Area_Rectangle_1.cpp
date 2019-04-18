// diagonal
class Solution {
public:
  int minAreaRect(vector<vector<int>> &points) {
    int n = points.size();
    unordered_set<int> uset;
    for (int i = 0; i < n; i++) {
      uset.insert(points[i][0] * 40001 + points[i][1]);
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (points[i][0] == points[j][0] || points[i][1] == points[j][1])
          continue;

        if (uset.count(points[i][0] * 40001 + points[j][1]) &&
            uset.count(points[j][0] * 40001 + points[i][1])) {
          ans = min(ans, abs(points[i][0] - points[j][0]) *
                             abs(points[i][1] - points[j][1]));
        }
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};
