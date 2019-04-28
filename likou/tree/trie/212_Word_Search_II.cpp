// 212_Word_Search_II
// trie
const int alphaSize = 26;
struct Node {
  bool end;
  Node *children[26];
  Node() {
    end = false;
    for (int i = 0; i < alphaSize; i++)
      children[i] = nullptr;
  }
};
class Solution {
private:
  vector<pair<int, int>> diff = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

  Node *root = new Node();
  vector<string> ans;
  set<pair<int, int>> seen;

  void build(string str) {
    Node *node = root;
    for (int i = 0; i < str.size(); i++) {
      int ch = str[i] - 'a';
      if (!node->children[ch])
        node->children[ch] = new Node();
      node = node->children[ch];
    }
    node->end = true;
  }
  bool search(string str) {
    Node *node = root;
    for (int i = 0; i < str.size(); i++) {
      int ch = str[i] - 'a';
      if (!node->children[ch])
        return false;
      node = node->children[ch];
    }
    return true;
  }
  bool find(string str) {
    Node *node = root;
    for (int i = 0; i < str.size(); i++) {
      int ch = str[i] - 'a';
      if (!node->children[ch])
        return false;
      node = node->children[ch];
    }
    if (node->end) {
      node->end = false;
      return true;
    }
    return false;
  }

  void dfs(int x, int y, vector<vector<char>> &board, string &tmp) {
    if (!search(tmp))
      return;
    if (find(tmp))
      ans.push_back(tmp);

    for (int i = 0; i < diff.size(); i++) {
      int curX = x + diff[i].first;
      int curY = y + diff[i].second;

      if (curX >= 0 && curX < board.size() && curY >= 0 &&
          curY < board[0].size() && !seen.count({curX, curY})) {
        tmp += board[curX][curY];
        seen.insert({curX, curY});
        dfs(curX, curY, board, tmp);
        seen.erase({curX, curY});
        tmp.pop_back();
      }
    }
    return;
  }

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    for (auto str : words) {
      build(str);
    }

    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        string tmp = "";
        tmp += board[i][j];
        seen.insert({i, j});
        dfs(i, j, board, tmp);
        seen.erase({i, j});
      }
    }
    return ans;
  }
};
