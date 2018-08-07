#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
private:
  int gcd(int x, int y) {
    if (x == 0)
      return y;
    else
      return gcd(y % x, x);
  }

public:
  int nthMagicalNumber(int N, int A, int B) {
    int mod = 1e9 + 7;
    int lcm = A / gcd(A, B) * B;
    int ans = 0;
    int n = lcm / A + lcm / B - 1;
    int m = N / n;
    int r = N % n;

    ans = (long)lcm * m % mod;
    if (r == 0) {
    } else {
      vector<int> tmp = {A, B};
      for (int i = 0; i < r - 1; i++) {
        if (tmp[0] < tmp[1]) {
          tmp[0] += A;
        } else {
          tmp[1] += B;
        }
      }
      ans = (ans + min(tmp[0], tmp[1]) % mod) % mod;
    }
    return ans;
  }
};

int main() {
  Solution solution = Solution();
  cout << solution.nthMagicalNumber(4, 2, 3);

  return 0;
}
