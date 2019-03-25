class Solution {
private:
  string binary(int i) {
    string tmp = "";
    while (i) {
      tmp += (i % 2) + '0';
      i /= 2;
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
  }

public:
  bool queryString(string S, int N) {
    if (N > 512)
      return false;

    int tmp = 1;
    int c = 0;
    while (tmp <= N) {
      tmp *= 2;
      c++;
    }
    tmp /= 2;
    for (int i = N; i >= tmp / 2; i--) {
      if (S.find(binary(i)) == string::npos)
        return false;
    }

    return true;
  }
};
