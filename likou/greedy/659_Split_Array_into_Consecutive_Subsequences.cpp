// 659_Split_Array_into_Consecutive_Subsequences
// greedy
class Solution {
public:
  bool isPossible(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> count;
    unordered_map<int, int> tail;
    for (auto x : nums)
      count[x]++;
    for (auto x : nums) {
      if (!count[x])
        continue;
      if (tail[x]) {
        tail[x]--;
        tail[x + 1]++;
      } else if (count[x + 1] && count[x + 2]) {
        count[x + 1]--;
        count[x + 2]--;
        tail[x + 3]++;
      } else
        return false;
      count[x]--;
    }
    return true;
  }
};
