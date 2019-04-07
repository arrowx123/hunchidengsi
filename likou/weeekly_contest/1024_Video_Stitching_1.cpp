class Solution {
public:
  int videoStitching(vector<vector<int>> &clips, int T) {
    sort(clips.begin(), clips.end(),
         [](const vector<int> &v1, const vector<int> &v2) {
           if (v1[0] != v2[0])
             return v1[0] < v2[0];
           else
             return v1[1] < v2[1];
         });
    if (clips[0][0])
      return -1;

    int ans = 0;

    int r = 0;
    int i = 0;
    while (r < T) {
      bool cover = false;
      int max_ = INT_MIN;
      for (; i < clips.size(); i++) {
        if (clips[i][0] > r)
          break;
        max_ = max(max_, clips[i][1]);
        cover = true;
      }
      if (!cover)
        return -1;
      r = max_;
      ans++;
    }

    if (r < T)
      return false;
    return ans;
  }
};
