// 139_Word_Break
// bfs
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict;
    for (int i = 0; i < wordDict.size(); i++)
      dict.insert(wordDict[i]);

    unordered_set<int> visited;
    queue<int> que;

    que.push(0);
    visited.insert(0);

    while (que.size()) {
      int idx = que.front();
      que.pop();

      if (idx == s.size())
        return true;
      string tmp = "";
      for (int i = idx; i < s.size(); i++) {
        tmp += s[i];
        if (dict.count(tmp) && !visited.count(i + 1)) {
          que.push(i + 1);
          visited.insert(i + 1);
        }
      }
    }
    return false;
  }
};
