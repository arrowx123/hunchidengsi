// 1040_Moving_Stones_Until_Consecutive_II
// math
class Solution {
public:
  vector<int> numMovesStonesII(vector<int> &stones) {
    sort(stones.begin(), stones.end());

    int n = stones.size();
    int s = 0;
    int e = 0;
    int maxLen = INT_MIN;
    for (int i = 0; i < n; i++) {
      int end = stones[i] + n - 1;
      int j = i;
      while (j < n && stones[j] <= end)
        j++;

      if (j - i > maxLen ||
          (j - i == maxLen &&
           stones[j - 1] - stones[i] > stones[e - 1] - stones[s])) {
        s = i;
        e = j;
        maxLen = j - i;
      }
    }

    int minGap = n - maxLen;
    if (maxLen == n - 1 && stones[e - 1] - stones[s] + 1 == n - 1)
      minGap++;
    int maxGap =
        max(stones[n - 1] - stones[1], stones[n - 2] - stones[0]) - (n - 2);
    return {minGap, maxGap};
  }
};
