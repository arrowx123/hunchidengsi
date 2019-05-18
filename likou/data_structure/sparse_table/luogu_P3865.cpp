// luogu_P3865
// sparse_table
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

const int maxn = 1e5 + 10;
const int logn = 17;
int f[maxn][logn];
int lgn[maxn];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    int tmp;
    scanf("%d", &tmp);
    f[i][0] = tmp;
  }

  lgn[1] = 0;
  lgn[2] = 1;
  for (int i = 3; i <= n; i++)
    lgn[i] = lgn[i / 2] + 1;

  for (int j = 1; j < logn; j++) {
    for (int i = 1; i + (1 << (j - 1)) <= n; i++) {
      f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }

  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int s = lgn[y - x + 1];
    printf("%d\n", max(f[x][s], f[y - (1 << s) + 1][s]));
  }
  return 0;
}
