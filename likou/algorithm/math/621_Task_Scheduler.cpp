// 621_Task_Scheduler
// math
class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    vector<int> cnt(26);
    for (int i = 0; i < tasks.size(); i++)
      cnt[tasks[i] - 'A']++;
    sort(cnt.begin(), cnt.end());

    int max_ = cnt.back() - 1;
    int empty = max_ * (n + 1);
    for (int i = 0; i < 26; i++)
      empty -= min(max_, cnt[i]);
    return empty > 0 ? empty + tasks.size() : tasks.size();
  }
};
