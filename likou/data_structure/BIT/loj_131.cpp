// loi_131
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

int read() {
  int s = 0, f = 1;
  char c = getchar();

  while (c < '0' || c > '9') {
    if (c == '-')
      f = -1;
    c = getchar();
  }

  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * f;
}

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
	n = read();
	q = read();

  for (int i = 1; i <= n; i++) {
    int tmp = read();
    add(i, tmp);
    add(i + 1, -tmp);
  }

  while (q--) {
		int op = read();

    if (op == 1){
			int l = read(),  r = read(), x = read();
			add(l, x);
			add(r + 1, -x);
		}
    else{
			int idx = read();
			printf("%lld\n", sum(idx));
		}
  }

  return 0;
}
