// 621_Task_Scheduler
// greedy
class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    vector<int> cnt(26);
    for (int i = 0; i < tasks.size(); i++)
      cnt[tasks[i] - 'A']++;
    sort(cnt.begin(), cnt.end());

    int ans = 0;
    while (cnt.back()) {
      int i = 0;
      while (i <= n) {
        if (!cnt.back())
          break;
        if (i < 26 && cnt[25 - i])
          cnt[25 - i]--;
        i++;
        ans++;
      }
      sort(cnt.begin(), cnt.end());
    }
    return ans;
  }
};
