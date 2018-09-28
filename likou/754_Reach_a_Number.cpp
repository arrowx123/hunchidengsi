#include <algorithm>
#include <iostream>
#include <math.h>
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
  int reachNumber(int target) {
    target = abs(target);
    int d = 0;
    int sum = 0;
    while (true) {
      d++;
      sum += d;
      if (sum >= target)
        break;
    }

    return (sum - target) % 2 == 0 ? d : d + 1 + d % 2;
  }
};
int main() {
  int target = 3;
  Solution solution;
  cout << solution.reachNumber(target);
  return 0;
}
