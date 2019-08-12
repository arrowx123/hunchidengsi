// 1155_Number_of_Dice_Rolls_With_Target_Sum
// dp
typedef long long ll;
const int mod = 1e9 + 7;

class Solution {
public:
  int numRollsToTarget(int d, int f, int target) {
    vector<vector<int>> cnt(d + 1, vector<int>(target + 1));
    for (int i = 1; i <= f && i <= target; i++)
      cnt[1][i] = 1;

    for (int i = 2; i <= d; i++) {
      for (int j = 1; j <= target; j++) {
        for (int k = 1; k <= f && k < j; k++) {
          cnt[i][j] = ((cnt[i][j] % mod) + (cnt[i - 1][j - k] % mod)) % mod;
        }
      }
    }
    return cnt[d][target];
  }
};

// dp
const int mod = 1e9 + 7;

class Solution {
public:
  int numRollsToTarget(int d, int f, int target) {
    vector<int> cnt(target + 1);
    cnt[0] = 1;

    for (int i = 0; i < d; i++) {
      for (int j = target; j >= 0; j--) {
        cnt[j] = 0;
        for (int k = 1; k <= j && k <= f; k++)
          cnt[j] = (cnt[j] + cnt[j - k]) % mod;
      }
    }
    return cnt[target];
  }
};
