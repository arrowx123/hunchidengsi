// O(1) time O(1) space
class Solution {
public:
  int findMinDifference(vector<string> &timePoints) {
    vector<bool> v(24 * 60, false);
    for (int i = 0; i < timePoints.size(); i++) {
      int t = ((timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0')) * 60 +
              (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
      if (v[t])
        return 0;
      v[t] = true;
    }

    int ans = INT_MAX;
    int init = -1;
    int l = -1;
    for (int i = 0; i < v.size(); i++) {
      if (v[i]) {
        if (l == -1) {
          l = i;
          init = i;
        } else {
          ans = min(ans, i - l);
          l = i;
        }
      }
    }

    ans = min(ans, init + 24 * 60 - l);
    return ans;
  }
};
