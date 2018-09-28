#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  string decodeAtIndex(string S, int K) {
    int n = S.size();
    long size = 0;
    string ans = "";
    for (int i = 0; i < n; i++) {
      if (isdigit(S[i])) {
        size *= S[i] - '0';
      } else {
        size++;
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      K %= size;
      if (!K && !isdigit(S[i])) {
        ans += S[i];
        break;
      }

      if (isdigit(S[i]))
        size /= S[i] - '0';
      else
        size--;
    }
    return ans;
  }
};
int main() {
  string S = "leet2code3";
  int K = 10;
  Solution solution = Solution();
  cout << solution.decodeAtIndex(S, K);

  return 0;
}
