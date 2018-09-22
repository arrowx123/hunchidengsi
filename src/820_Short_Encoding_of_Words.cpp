#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
  bool contain(string s1, string s2) {
    string tmp = s1.substr(s1.size() - s2.size(), s2.size());
    if (tmp.compare(s2) == 0)
      return true;
    return false;
  }
  static bool cmp(string s1, string s2) { return s1.size() > s2.size(); }

public:
  int minimumLengthEncoding(vector<string> &words) {
    int len = words.size();
    int ans = 0;
    vector<bool> visited(len);
    sort(words.begin(), words.end(), cmp);
    for (int i = 0; i < len; i++) {
      if (visited[i])
        continue;
      visited[i] = true;
      ans += words[i].size() + 1;
      for (int j = i + 1; j < len; j++) {
        if (contain(words[i], words[j]))
          visited[j] = true;
      }
    }
    return ans;
  }
};
int main() {
  vector<string> words = {"time", "me", "bell"};
  Solution solution;
  cout << solution.minimumLengthEncoding(words);

  return 0;
}
