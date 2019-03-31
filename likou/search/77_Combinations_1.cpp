// bfs
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    queue<vector<int>> que;
    for (int i = 1; i <= n; i++) {
      que.push(vector<int>{i});
    }

    while (que.size()) {
      vector<int> cur = que.front();
      que.pop();

      if (cur.size() == k) {
        ans.push_back(cur);
        continue;
      }

      int pos = cur.back();
      int len = cur.size();
      for (int i = pos + 1; i <= n + 1 - (k - len); i++) {
        que.push(cur);
        que.back().push_back(i);
      }
    }
    return ans;
  }
};
