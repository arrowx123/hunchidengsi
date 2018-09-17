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
    vector<pair<int, int>> b;
    int ans = 0;

    int tmp = tree[0];
    int cnt = 1;
    for (int i = 1; i < len; i++) {
      if (tree[i] != tmp) {
        b.push_back({tmp, cnt});
        cnt = 1;
        tmp = tree[i];
      } else {
        cnt++;
      }
    }
    b.push_back({tmp, cnt});

		for(int i = 0; i < (int)b.size(); i ++){
			cout << b[i].first << " " << b[i].second << endl;
		}

    unordered_set<int> uset;
		int c_cnt = 0;
    for (int i = 0; i < (int)b.size(); i++) {
      if (uset.find(b[i].first) != uset.end())
        c_cnt += b[i].second;
      else {
        if (uset.size() == 2) {
          i -= 2;
          uset.clear();
          c_cnt = 0;
        } else {
          c_cnt += b[i].second;
          uset.insert(b[i].first);
        }
      }
      ans = max(ans, c_cnt);
    }

    return ans;
  }
};
int main() {
  vector<int> tree = {3,3,3,1,2,1,1,2,3,3,4};
  Solution solution;
  cout << solution.totalFruit(tree);
  return 0;
}
