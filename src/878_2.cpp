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

    long lo = 0;
    long hi = 1e15;

    while (lo < hi) {
      long mid = lo + (hi - lo) / 2;
      if (mid / A + mid / B - mid / lcm < N) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo % mod;
  }
};

int main() {
  Solution solution = Solution();
  cout << solution.nthMagicalNumber(3, 8, 9);

  return 0;
}
