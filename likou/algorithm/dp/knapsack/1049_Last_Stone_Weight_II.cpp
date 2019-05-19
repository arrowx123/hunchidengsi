// 1049_Last_Stone_Weight_II
// knapsack
class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int n = stones.size();
    int l = n / 2;
    int r = n - l;

    set<int> a, b;

    for (int i = 0; i < (1 << l); i++) {
      int sum = 0;
      for (int j = 0; j < l; j++) {
        if (i & (1 << j))
          sum += stones[j];
        else
          sum -= stones[j];
      }
      a.insert(sum);
    }

    for (int i = 0; i < (1 << r); i++) {
      int sum = 0;
      for (int j = 0; j < r; j++) {
        if (i & (1 << j))
          sum += stones[l + j];
        else
          sum -= stones[l + j];
      }
      b.insert(sum);
    }

    int ans = INT_MAX;

    for (auto ele : a) {
      set<int>::iterator it = lower_bound(b.begin(), b.end(), ele);
      if (it != b.end())
        ans = min(ans, *it - ele);
      else if (it != b.begin()) {
        it--;
        ans = min(ans, ele - *it);
      }
    }
    return ans;
  }
};
