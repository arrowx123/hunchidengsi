// math
// https://leetcode.com/problems/numbers-with-repeated-digits/discuss/258212/Share-my-O(logN)-C%2B%2B-DP-solution-with-proof-and-explanation
class Solution {
public:
  int numDupDigitsAtMostN(int N) {

    vector<int> digits;
    int num = N;
    while (N) {
      digits.push_back(N % 10);
      N /= 10;
    }
    reverse(digits.begin(), digits.end());

    // calculate part 1
    vector<int> sum1(digits.size() - 1);
    for (int i = 0; i < digits.size() - 1; i++) {
      dp1[i] = i == 0 ? 9 : dp1[i - 1] * (10 - i);
    }

    // calculate part 2
    vector<int> sum2(digits.size());
    vector<int> cnt(10);
    fill(cnt.begin(), cnt.end(), 0);
    bool duplicate = false;
    for (int i = 0; i < digits.size(); i++) {
      sum2[i] = i == 0 ? 9 : sum2[i - 1] * (10 - i);
      if (!duplicate) {
        int diff = 0;
        for (int j = digits[i] + 1; j < 10; j++) {
          diff += cnt[j] == 0;
        }
        sum2[i] -= diff;
        cnt[digits[i]]++;
        if (cnt[digits[i]] > 1)
          duplicate = true;
      }
    }
    return num - accumulate(sum1.begin(), sum1.end(), 0) - sum2[digits.size() - 1];
  }
};
