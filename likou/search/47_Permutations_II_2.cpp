// next permutation
class Solution {
private:
  bool next_permut(vector<int> &nums) {
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        for (int j = nums.size() - 1; j >= i + 1; j++) {
          if (nums[j] > nums[i]) {
            swap(nums[j], nums[i]);
            break;
          }
        }
        reverse(nums.begin() + i + 1, nums.end());
        return true;
      }
    }
    return false;
  }

public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> all_perm;
    do
      all_perm.push_back(nums);
    while (next_permutation(nums.begin(), nums.end()));
    return all_perm;
  }
};
