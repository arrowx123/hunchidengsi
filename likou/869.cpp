#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
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
  bool equal(vector<int> v1, vector<int> v2) {
    if (v1.size() != v2.size())
      return false;
    for (int i = 0; i < (int)v1.size(); i++) {

      if (v1[i] != v2[i])
        return false;
    }
    return true;
  }

public:
  bool reorderedPowerOf2(int N) {
    int num = 1;
    set<vector<int>> uset;
    vector<int> digits;

    for (int i = 0; i < 30; i++) {
      vector<int> tmp;
      int num_cp = num;
      while (num_cp) {
        tmp.push_back(num_cp % 10);
        num_cp /= 10;
      }
      sort(tmp.begin(), tmp.end());
      uset.insert(tmp);
      num *= 2;
    }
    while (N) {
      digits.push_back(N % 10);
      N /= 10;
    }
    sort(digits.begin(), digits.end());
    for (auto ele : uset) {
      if (equal(ele, digits))
        return true;
    }
    return false;
  }
};
int main() {
  int N = 46;
  Solution solution = Solution();
  cout << solution.reorderedPowerOf2(N);
  return 0;
}
