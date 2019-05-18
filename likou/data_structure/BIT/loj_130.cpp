// loi_130
// BIT
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;

const int maxn = 1e6 + 10;
ll nums[maxn];
int n, q;

int lowbit(int x) { return x & (-x); }

void add(int idx, int v) {
  while (idx <= n) {
    nums[idx] += v;
    idx += lowbit(idx);
  }
}

ll sum(int idx) {
  ll ret = 0;
  while (idx >= 1) {
    ret += nums[idx];
    idx -= lowbit(idx);
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &q);

  for (int i = 1; i <= n; i++) {
    int tmp;
    scanf("%d", &tmp);
    int j = i;
    add(j, tmp);
  }

  while (q--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == 1)
      add(b, c);
    else
      printf("%lld\n", sum(c) - sum(b - 1));
  }

  return 0;
}
