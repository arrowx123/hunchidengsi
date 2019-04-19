class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> umap;
    umap[0] = 1;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      ans += umap[sum - k];
      umap[sum]++;
    }
    return ans;
  }
};
