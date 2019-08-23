// 862_Shortest_Subarray_with_Sum_at_Least_K
// sliding_window
// O(n)
class Solution {
public:
  int shortestSubarray(vector<int> &A, int K) {
    int n = A.size();
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++)
      sum[i + 1] = sum[i] + A[i];

    deque<int> deq;
    int ans = INT_MAX;
    for (int i = 0; i <= n; i++) {
      while (deq.size() && sum[deq.back()] >= sum[i])
        deq.pop_back();
      while (deq.size() && sum[i] - K >= sum[deq.front()]) {
        ans = min(ans, i - deq.front());
        deq.pop_front();
      }
      deq.push_back(i);
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
