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
  int f(int x, int K, int N) {

    int ans = 0;
    int r = 1;
    for (int i = 1; i <= K; i++) {
      r *= x - i + 1;
      r /= i;
      ans += r;
      if (ans >= N)
        break;
    }
    return ans;
  }

public:
  int superEggDrop(int K, int N) {
    int l = 1;
    int r = N;

    while (l < r) {
      int mid = (l + r) / 2;
      if (f(mid, K, N) < N) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
};

int main() {
  int K = 3;
  int N = 14;
  Solution solution = Solution();
  cout << solution.superEggDrop(K, N);
  return 0;
}
