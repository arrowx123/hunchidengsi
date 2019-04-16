// dfs + pruning
class Solution {
private:
  int avg = 0;
  vector<bool> used;
  bool dfs(vector<int> &nums, int k, int cnt, int pos, int sum) {
    if (sum == avg) {
      return dfs(nums, k, cnt + 1, 0, 0);
    }
    if (sum > avg) {
      return false;
    }

    if (k == cnt)
      return true;

    for (int i = pos; i < nums.size(); i++) {
      if (used[i])
        continue;

      used[i] = true;
      if (dfs(nums, k, cnt, i + 1, sum + nums[i]))
        return true;
      used[i] = false;
    }
    return false;
  }

public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k)
      return false;

    avg = sum / k;
    used.resize(nums.size());
    return dfs(nums, k, 0, 0, 0);
  }
};
