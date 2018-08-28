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
private:
  unordered_map<int, int> umap;
  int dp(int K, int N) {
    int ans;
    if (!umap.count(N * 100 + K)) {

      if (N == 0)
        ans = 0;
      else if (K == 1)
        ans = N;
      else {
        int l = 1;
        int r = N;

        while (l + 1 < r) {
          int mid = (l + r) / 2;
          int t1 = dp(K - 1, mid - 1);
          int t2 = dp(K, N - mid);

          if (t1 < t2)
            l = mid;
          else if (t1 > t2)
            r = mid;
          else
            l = r = mid;
        }
        ans = 1 + min(max(dp(K - 1, l - 1), dp(K, N - l)),
                      max(dp(K - 1, r - 1), dp(K, N - r)));
      }

      umap[N * 100 + K] = ans;
    }
    return umap[N * 100 + K];
  }

public:
  int superEggDrop(int K, int N) { return dp(K, N); }
};

int main() {
  int K = 3;
  int N = 14;
  Solution solution = Solution();
  cout << solution.superEggDrop(K, N);
  return 0;
}
