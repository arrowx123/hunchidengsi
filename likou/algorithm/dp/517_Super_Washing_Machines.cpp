// 517_Super_Washing_Machines
// dp
class Solution {
public:
  int findMinMoves(vector<int> &machines) {
    int sum = 0;
    for (auto m : machines)
      sum += m;

    if (sum % machines.size())
      return -1;
    for (int &m : machines)
      m -= sum / machines.size();

    int ans = 0;
    int cur_sum = 0;
    int max_sum = 0;
    for (int m : machines) {
      cur_sum += m;
      max_sum = max(max_sum, abs(cur_sum));
      ans = max(ans, max(max_sum, m));
    }
    return ans;
  }
};
