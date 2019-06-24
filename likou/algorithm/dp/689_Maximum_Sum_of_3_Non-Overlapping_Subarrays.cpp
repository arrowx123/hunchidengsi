// 689_Maximum_Sum_of_3_Non-Overlapping_Subarrays
// dp
class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    vector<pair<int, int>> l(n);
    vector<pair<int, int>> r(n);

    int tmp = 0;
    for (int i = 0; i < k - 1; i++)
      tmp += nums[i];
    for (int i = 0; i < n - k + 1; i++) {
      tmp += nums[i + k - 1];
      l[i] = {i, tmp};
      tmp -= nums[i];
      if (i && l[i].second <= l[i - 1].second)
        l[i] = l[i - 1];
    }

    tmp = 0;
    for (int i = 0; i < k - 1; i++)
      tmp += nums[n - 1 - i];
    for (int i = n - k; i >= 0; i--) {
      tmp += nums[i];
      r[i] = {i, tmp};
      tmp -= nums[i + k - 1];
      if (i + 1 < n && r[i + 1].second > r[i].second)
        r[i] = r[i + 1];
    }

    int max_ = 0;
    vector<int> ret;
    tmp = 0;
    for (int i = 0; i < k - 1; i++)
      tmp += nums[i + k];
    for (int i = k; i < n - 2 * k + 1; i++) {
      tmp += nums[i + k - 1];
      if (tmp + l[i - k].second + r[i + k].second > max_) {
        max_ = tmp + l[i - k].second + r[i + k].second;
        ret = {l[i - k].first, i, r[i + k].first};
      }
      tmp -= nums[i];
    }
    return ret;
  }
};
