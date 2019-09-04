// 995_Minimum_Number_of_K_Consecutive_Bit_Flips
// segment_tree
// O(nlog(n))
class Node {
public:
  int total, sum;
  bool rev;
  Node(int total, int sum) {
    this->total = total;
    this->sum = sum;
    rev = false;
  }
  Node() {
    total = sum = 0;
    rev = false;
  }
};

class Solution {
private:
  vector<int> a;
  vector<Node> seg;

  void update(int idx) {
    seg[idx].rev = !seg[idx].rev;
    seg[idx].sum = seg[idx].total - seg[idx].sum;
  }

  void passDown(int idx) {
    if (!seg[idx].rev)
      return;
    update(idx * 2 + 1);
    update(idx * 2 + 2);
    seg[idx].rev = false;
    return;
  }

  void passUp(int idx) {
    seg[idx].sum = seg[idx * 2 + 1].sum + seg[idx * 2 + 2].sum;
  }

  int build(int idx, int l, int r) {
    if (l == r) {
      seg[idx] = Node(1, a[l]);
      return seg[idx].sum;
    }
    int mid = (l + r) / 2;
    seg[idx] = Node(r - l + 1, build(idx * 2 + 1, l, mid) +
                                   build(idx * 2 + 2, mid + 1, r));
    return seg[idx].sum;
  }

  void rev(int idx, int l, int r, int i, int j) {
    if (i <= l && j >= r) {
      update(idx);
      return;
    }
    if (i > r || j < l)
      return;
    passDown(idx);
    int mid = (l + r) / 2;
    rev(idx * 2 + 1, l, mid, i, j);
    rev(idx * 2 + 2, mid + 1, r, i, j);
    passUp(idx);
    return;
  }

  int query(int idx, int l, int r, int i, int j) {
    if (i <= l && j >= r)
      return seg[idx].sum;
    if (i > r || j < l)
      return 0;
    passDown(idx);
    int mid = (l + r) / 2;
    return query(idx * 2 + 1, l, mid, i, j) +
           query(idx * 2 + 2, mid + 1, r, i, j);
  }

public:
  int minKBitFlips(vector<int> &A, int k) {
    this->a = A;
    int n = a.size();
    seg.resize(4 * n);

    build(0, 0, n - 1);
    int ans = 0;
    for (int i = 0; i < n - k + 1; i++) {
      int cur = query(0, 0, n - 1, i, i);
      if (!cur) {
        rev(0, 0, n - 1, i, i + k - 1);
        ans++;
      }
    }

    int cur = query(0, 0, n - 1, n - k + 1, n - 1);
    if (cur != k - 1)
      return -1;
    return ans;
  }
};

// O(n)
// bit_operation
class Solution {
public:
  int minKBitFlips(vector<int> &A, int K) {
    int n = A.size();
    vector<int> hint(n);
    int flip = 0, ans = 0;

    for (int i = 0; i < n; i++) {
      flip ^= hint[i];
      if (A[i] == flip) {
        ans++;
        if (i + K > n)
          return -1;
        if (i + K < n)
          hint[i + K] ^= 1;
        flip ^= 1;
      }
    }
    return ans;
  }
};
