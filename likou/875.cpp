#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
private:
  bool possible(int s, vector<int> &piles, int h) {
    int len = piles.size();
    int ans = 0;
    for (int i = 0; i < len; i++) {
      ans += (piles[i] - 1) / s + 1;
    }
    return ans <= h;
  }

public:
  int minEatingSpeed(vector<int> &piles, int H) {

    long lo = 1;
    long hi = 1e9;
    while (lo < hi) {
      long mid = lo + (hi - lo) / 2;
      if (possible(mid, piles, H))
        hi = mid;
      else
        lo = mid + 1;
    }

    return lo;
  }
};
int main() {
  vector<int> piles = {312884470};
  int H = 968709470;
  Solution solution = Solution();
  cout << solution.minEatingSpeed(piles, H);

  return 0;
}
