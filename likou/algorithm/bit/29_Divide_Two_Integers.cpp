// 29_Divide_Two_Integers
// bit
typedef long long ll;
class Solution {
public:
  int divide(int dividend, int divisor) {
    ll d1 = abs((ll)dividend);
    ll d2 = abs((ll)divisor);

    ll ans = 0;
    ll tmp = 1;

    while (true) {
      while (d1 > d2) {
        d2 <<= 1;
        tmp *= 2;
      }
      while (d1 < d2) {
        d2 >>= 1;
        tmp /= 2;
      }

      if (d2 < abs((ll)divisor))
        break;

      d1 -= d2;
      ans += tmp;
    }

    ans = ((dividend >= 0 && divisor >= 0) || (dividend <= 0 && divisor <= 0))
              ? ans
              : -ans;

    if (ans > INT_MAX)
      return INT_MAX;
    else if (ans < INT_MIN)
      return INT_MIN;
    return ans;
  }
};
