// dp
#define INF 1 << 30
class Solution {
public:
  int videoStitching(vector<vector<int>> &clips, int T) {
    sort(clips.begin(), clips.end(),
         [](const vector<int> &v1, const vector<int> &v2) {
           return v1[1] < v2[1];
         });

    vector<int> dp(clips.size(), 0);
    for (int i = 0; i < clips.size(); i++) {
      dp[i] = clips[i][0] == 0 ? 1 : INF;

      for (int j = 0; j < i; j++) {
        if (clips[j][1] >= clips[i][0]) {
          dp[i] = min(dp[i], dp[j] + 1);
        }
      }
    }

    int ret = INF;
    for (int i = 0; i < dp.size(); i++) {
      if (clips[i][1] >= T) {
        ret = min(ret, dp[i]);
      }
    }
    return ret == INF ? -1 : ret;
  }
};
