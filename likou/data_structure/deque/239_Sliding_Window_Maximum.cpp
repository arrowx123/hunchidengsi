// 239_Sliding_Window_Maximum
// deque
class Solution {
private:
  deque<int> deq;
  vector<int> nums;

  void cleanDeq(int idx, int val, int k) {
    while (deq.size() && deq.front() < idx - k + 1)
      deq.pop_front();
    while (deq.size() && nums[deq.back()] <= val)
      deq.pop_back();
  }

public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    this->nums = nums;
    for (int i = 0; i < k - 1; i++) {
      cleanDeq(i, nums[i], k);
      deq.push_back(i);
    }

    vector<int> ans;
    for (int i = k - 1; i < nums.size(); i++) {
      cleanDeq(i, nums[i], k);
      deq.push_back(i);
      ans.push_back(nums[deq.front()]);
    }
    return ans;
  }
};
