// 698_Partition_to_K_Equal_Sum_Subsets
// recursion with memorization
// O(n2^n)
class Solution {
private:
  vector<int> v;
  int sum;
  int k;
  unordered_set<int> used;
  bool bf(int csum, int pos) {
    if (csum > sum / k)
      return false;
    if (csum == sum / k)
      return bf(0, 0);
    if (used.size() == v.size())
      return true;
    for (int i = pos; i < v.size(); i++) {
      if (used.count(i))
        continue;
      used.insert(i);
      if (bf(csum + v[i], i + 1))
        return true;
      used.erase(i);
    }
    return false;
  }

public:
  bool canPartitionKSubsets(vector<int> &nums, int kk) {
    v = nums;
    sum = 0;
    k = kk;
    for (int n : nums)
      sum += n;
    if (sum % k)
      return false;
    return bf(0, 0);
  }
};

// SCDP
// O(n2^n)
// top down
class Solution {
private:
  vector<int> v;
  int k;
  int sum;
  unordered_map<int, bool> dp;
  bool recursion(int used, int csum) {
    if (dp.count(used))
      return dp[used];

    for (int i = 0; i < v.size(); i++) {
      if (used & (1 << i))
        continue;
      if (csum % (sum / k) + v[i] <= sum / k) {
        if (recursion(used | (1 << i), csum + v[i]))
          return dp[used] = true;
      }
    }
    return dp[used] = false;
  }

public:
  bool canPartitionKSubsets(vector<int> &nums, int kk) {
    sum = 0;
    v = nums;
    k = kk;

    for (int n : nums)
      sum += n;
    if (sum % k)
      return false;
    dp[(1 << nums.size()) - 1] = true;
    return recursion(0, 0);
  }
};

// SCDP
// O(n2^n)
// bottom up
class Solution {
public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int s = 0;
    for (int n : nums)
      s += n;
    if (s % k)
      return false;

    unordered_map<int, bool> dp;
    unordered_map<int, int> sum;
    dp[0] = true;

    for (int i = 0; i < (1 << nums.size()); i++) {
      if (!dp[i])
        continue;

      for (int j = 0; j < nums.size(); j++) {
        if (i & (1 << j))
          continue;
        if (sum[i] % (s / k) + nums[j] <= s / k) {
          dp[i | (1 << j)] = true;
          sum[i | (1 << j)] = sum[i] + nums[j];
        }
      }
    }
    return dp[(1 << nums.size()) - 1];
  }
};
