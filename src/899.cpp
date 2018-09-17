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
  string orderlyQueue(string S, int K) {
    string ans = "";
    if (K == 1) {
      ans = S;
      string tmp = S;
      for (int i = 0; i < (int)S.size() - 1; i++) {
				tmp = tmp.substr(1) + tmp[0];
        if (ans.compare(tmp) > 0)
          ans = tmp;
      }
    } else {
      sort(S.begin(), S.end());
      ans = S;
    }
    cout << ans << endl;
    return ans;
  }
};
int main() {
  string S = "baaca";
  int K = 1;
  Solution solution = Solution();
  solution.orderlyQueue(S, K);
  return 0;
}
