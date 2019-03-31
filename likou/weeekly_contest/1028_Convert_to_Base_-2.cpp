class Solution {
public:
  string baseNeg2(int N) {
    if (!N)
      return "0";
    string ans = "";
    while (N) {
      int c = N % (-2);
      if (c == -1) {
        c = 1;
        N--;
      }
      ans += c + '0';
      N /= -2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
