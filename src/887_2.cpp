#include <algorithm>
#include <iostream>
#include <math.h>
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
public:
  int superEggDrop(int K, int N) {
    vector<int> dp(N + 1);
    for (int i = 0; i <= N; i++) {
      dp[i] = i;
    }

    for (int i = 2; i <= K; i++) {
      vector<int> dp2(N + 1);

      int x = 1;
      for (int n = 1; n <= N; n++) {
        while (x < n && max(dp[x - 1], dp2[n - x]) > max(dp[x], dp2[n - x - 1]))
          x++;
        dp2[n] = 1 + max(dp[x - 1], dp2[n - x]);
      }
      dp = dp2;
    }

    return dp[N];
  }
};

int main() {
  int K = 3;
  int N = 14;
  Solution solution = Solution();
  cout << solution.superEggDrop(K, N);
  return 0;
}
