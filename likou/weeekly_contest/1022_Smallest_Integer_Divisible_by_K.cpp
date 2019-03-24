typedef long long ll;
class Solution {
public:
  int smallestRepunitDivByK(int K) {
    int val = 0;
    int length = 0;

    for (int i = 0; i < 1e6; i++) {
      val = val * 10 + 1;
      length++;

      val %= K;
      if (!val)
        return length;
    }
    return -1;
  }
};
