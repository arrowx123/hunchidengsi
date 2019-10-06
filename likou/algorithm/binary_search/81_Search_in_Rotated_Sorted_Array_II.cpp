// 81_Search_in_Rotated_Sorted_Array_II
// binary_search
// worst: O(n)
class Solution {
public:
  bool search(vector<int> &nums, int target) {
    if (!nums.size())
      return false;
    int l = 0, r = nums.size() - 1;

    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (nums[mid] >= nums[l] && nums[mid] < nums[r]) {
        if (target > nums[mid])
          l = mid + 1;
        else
          r = mid;
      } else if (nums[mid] <= nums[l] && nums[mid] < nums[r]) {
        if (target >= nums[l])
          r = mid;
        else if (target > nums[mid])
          l = mid + 1;
        else
          r = mid;
      } else if (nums[mid] >= nums[l] && nums[mid] > nums[r]) {
        if (target > nums[mid])
          l = mid + 1;
        else if (target >= nums[l])
          r = mid;
        else
          l = mid + 1;
      } else {
        if (nums[l] == target || nums[r] == target)
          return true;
        l++, r--;
      }
    }
    return nums[l] == target || nums[r] == target;
  }
};
