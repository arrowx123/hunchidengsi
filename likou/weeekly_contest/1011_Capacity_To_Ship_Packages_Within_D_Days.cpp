// binary search
class Solution {
private:
  bool possible(int v, vector<int> &weights, int D) {
    int tmp = 0;
    int ans = 0;
    for (int i = 0; i < weights.size(); i++) {
      if (weights[i] > v)
        return false;

      if (tmp + weights[i] > v) {
        tmp = 0;
        ans++;
      }
      tmp += weights[i];
    }
    ans++;
    return ans <= D;
  }

public:
  int shipWithinDays(vector<int> &weights, int D) {
    int sum = accumulate(weights.begin(), weights.end(), 0);
    int l = 0;
    int r = sum;

    while (l < r) {
      int mid = (l + r) / 2;
      if (possible(mid, weights, D)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};
