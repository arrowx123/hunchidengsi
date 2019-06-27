// 480_Sliding_Window_Median
// multiset
class Solution {
public:
  vector<double> medianSlidingWindow(vector<int> &nums, int k) {
    vector<double> ans;
    multiset<int> mset;

    for (int i = 0; i < k; i++)
      mset.insert(nums[i]);
    multiset<int>::iterator mid = next(mset.begin(), k / 2);

    for (int i = k; i <= nums.size(); i++) {
      ans.push_back(((double)(*mid) + (double)*prev(mid, 1 - k % 2)) / 2);
      if (i == nums.size())
        break;

      mset.insert(nums[i]);
      if (nums[i] < *mid)
        mid = prev(mid, 1);

      if (nums[i - k] <= *mid)
        mid = next(mid, 1);
      mset.erase(mset.find(nums[i - k]));
    }

    return ans;
  }
};
