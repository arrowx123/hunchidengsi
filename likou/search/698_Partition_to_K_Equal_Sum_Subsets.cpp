// dfs
class Solution {
private:
  vector<int> v;
  int avg = 0;
  bool dfs(vector<int> &nums, int k, int pos) {
    if (pos >= nums.size())
      return true;

    for (int i = 0; i < v.size(); i++) {
      if (v[i] + nums[pos] <= avg) {
        v[i] += nums[pos];
        if (dfs(nums, k, pos + 1))
          return true;
        v[i] -= nums[pos];
      }
      if (!v[i])
        break;
    }
    return false;
  }

public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k)
      return false;
    avg = sum / k;
    v.resize(k);
    return dfs(nums, k, 0);
  }
};
