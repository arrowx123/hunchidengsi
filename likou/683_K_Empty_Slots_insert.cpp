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
  int kEmptySlots(vector<int> &flowers, int k) {
    int len = flowers.size();
    set<int> uset;

    for (int i = 0; i < len; i++) {
      uset.insert(flowers[i]);
      set<int>::iterator it = uset.find(flowers[i]);
      if (it != uset.begin() && flowers[i] - *prev(it) == k + 1) {
        return i + 1;
      }

      if (next(it) != uset.end() && *next(it) - flowers[i] == k + 1) {
        return i + 1;
      }
    }
    return -1;
  }
};

int main() {
  vector<int> flowers = {1, 3, 2};
  int k = 1;
  Solution solution;
  cout << solution.kEmptySlots(flowers, k);
  return 0;
}
