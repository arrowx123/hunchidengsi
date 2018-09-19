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
  bool lemonadeChange(vector<int> &bills) {
    unordered_map<int, int> umap;
    int len = bills.size();

    for (int i = 0; i < len; i++) {
      if (bills[i] == 5)
        umap[5]++;
      else if (bills[i] == 10) {
        umap[10]++;
        umap[5]--;
        if (umap[5] < 0)
          return false;
      } else {
        umap[20]++;
        int cnt = 15;
        if (umap[10] > 0) {
          umap[10]--;
          cnt -= 10;
        }
        umap[5] -= cnt / 5;
        if (umap[5] < 0)
          return false;
      }
    }
    return true;
  }
};
int main() {
  vector<int> bills = {5, 5, 5, 10, 20};
  Solution solution;
  cout << solution.lemonadeChange(bills);
  return 0;
}
