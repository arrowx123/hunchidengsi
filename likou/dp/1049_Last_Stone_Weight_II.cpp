// 1049_Last_Stone_Weight_II
// dp
class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    unordered_set<int> uset;
    uset.insert(0);

    for (int i = 0; i < stones.size(); i++) {
      unordered_set<int> cset;
      for (auto ele : uset) {
        cset.insert(ele + stones[i]);
        cset.insert(ele - stones[i]);
      }
      uset = cset;
    }

    int ans = INT_MAX;
    for (auto ele : uset)
      if (ele >= 0)
        ans = min(ans, ele);
    return ans;
  }
};
