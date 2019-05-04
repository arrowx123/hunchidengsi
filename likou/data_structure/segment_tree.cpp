// 1032_Stream_of_Characters
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

vector<int> segmentTree;
int build(int idx, int start, int end, vector<int> &v) {
  if (start == end) {
    segmentTree[idx] = v[start];
    return v[start];
  }

  int mid = (start + end) / 2;
  int l = build(idx * 2 + 1, start, mid, v);
  int r = build(idx * 2 + 2, mid + 1, end, v);
  segmentTree[idx] = l + r;
  return segmentTree[idx];
}

void update(int idx, int start, int end, int pos, int val, vector<int> &v) {
  if (start == end) {
    segmentTree[idx] += val;
    v[pos] += val;
    return;
  }
  int mid = (start + end) / 2;
  if (pos <= mid)
    update(idx * 2 + 1, start, mid, pos, val, v);
  else
    update(idx * 2 + 1, mid + 1, end, pos, val, v);
  segmentTree[idx] = segmentTree[idx * 2 + 1] + segmentTree[idx * 2 + 2];
  return;
}

int rangeQuery(int idx, int start, int end, int l, int r) {
  if (l > end || r < start)
    return 0;
  if (l <= start && r >= end)
    return segmentTree[idx];

  int mid = (start + end) / 2;
  int p1 = rangeQuery(2 * idx + 1, start, mid, l, r);
  int p2 = rangeQuery(2 * idx + 2, mid + 1, end, l, r);
  return p1 + p2;
}

int rangeMin(int idx, int start, int end, int l, int r) {
  if (l > end || r < start)
    return INT_MAX;
  if (start == end)
    return segmentTree[idx];

  int mid = (start + end) / 2;
  int lMin = rangeMin(idx * 2 + 1, start, mid, l, r);
  int rMin = rangeMin(idx * 2 + 2, mid + 1, end, l, r);
  return min(lMin, rMin);
}

int main() {
  vector<int> v = {2, 1, 5, 3, 4};
  segmentTree.resize(v.size() * 4);
  build(0, 0, v.size() - 1, v);

  for (int ele : segmentTree)
    cout << ele << " ";

  char tmp;
  int l, r;
  scanf("%c %d %d", &tmp, &l, &r);
  cout << tmp << " " << l << " " << r << endl;
  return 0;
}
