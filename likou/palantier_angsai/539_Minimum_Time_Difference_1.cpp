class Solution {
public:
  int findMinDifference(vector<string> &timePoints) {
    vector<int> v;
    for (int i = 0; i < timePoints.size(); i++) {
      int t = ((timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0')) * 60 +
              (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
      v.push_back(t);
    }

    sort(v.begin(), v.end());
    int ans = INT_MAX;
    for (int i = 1; i < v.size(); i++) {
      ans = min(ans, v[i] - v[i - 1]);
    }

    ans = min(ans, v[0] + 24 * 60 - v.back());
    return ans;
  }
};
