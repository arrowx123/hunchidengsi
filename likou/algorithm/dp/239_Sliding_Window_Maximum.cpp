// 239_Sliding_Window_Maximum
// dp
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    if (!k)
      return vector<int>{};

    int n = nums.size();
    vector<int> left(n);
    vector<int> right(n);
    for (int i = 0; i < n; i++) {
      if (i % k == 0)
        left[i] = nums[i];
      else {
        if (i)
          left[i] = max(nums[i], left[i - 1]);
      }
    }

    right[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if ((i + 1) % k == 0)
        right[i] = nums[i];
      else {
        if (i < n - 1)
          right[i] = max(nums[i], right[i + 1]);
      }
    }
    vector<int> ans(n - k + 1);
    for (int i = 0; i < n - k + 1; i++) {
      ans[i] = max(right[i], left[i + k - 1]);
    }
    return ans;
  }
};
