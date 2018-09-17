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
public:
  int totalFruit(vector<int> &tree) {
    int len = tree.size();
    unordered_map<int, int> umap;
    int ans = 0;
    int cnt = 0;

    int i = -1;
    for (int j = 0; j < len; j++) {
      if (umap[tree[j]] == 0)
        cnt++;
      umap[tree[j]]++;
      while (cnt > 2) {
				i ++;
        umap[tree[i]]--;
        if (umap[tree[i]] == 0)
          cnt--;
      }
      ans = max(ans, j - i);
    }

    return ans;
  }
};
int main() {
  vector<int> tree = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  Solution solution;
  cout << solution.totalFruit(tree);
  return 0;
}
