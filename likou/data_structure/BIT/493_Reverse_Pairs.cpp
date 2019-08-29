// 493_Reverse_Pairs
// bit
// O(nlog(n))
class Solution {
private:
  vector<int> bit;

  int query(int idx) {
    int ret = 0;
    while (idx > 0) {
      ret += bit[idx];
      idx -= lowbit(idx);
    }
    return ret;
  }

  void update(int idx) {
    while (idx < bit.size()) {
      bit[idx] += 1;
      idx += lowbit(idx);
    }
  }

  int lowbit(int idx) { return idx & (-idx); }

public:
  int reversePairs(vector<int> &nums) {
    int n = nums.size();
    bit.resize(n + 1);

    vector<int> v = nums;
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans +=
          query(n) -
          query(lower_bound(v.begin(), v.end(), 2LL * nums[i] + 1) - v.begin());
      update(lower_bound(v.begin(), v.end(), nums[i]) - v.begin() + 1);
    }
    return ans;
  }
};

// segment_tree
class Solution {
private:
  vector<int> seg;

  void update(int idx, int l, int r, int pos) {
    if (l == r) {
      seg[idx] += 1;
      return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid)
      update(idx * 2 + 1, l, mid, pos);
    else
      update(idx * 2 + 2, mid + 1, r, pos);
    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
  }

  int query(int idx, int l, int r, int i, int j) {
    if (i > r || j < l)
      return 0;
    if (i <= l && j >= r)
      return seg[idx];
    int mid = (l + r) / 2;
    return query(idx * 2 + 1, l, mid, i, j) +
           query(idx * 2 + 2, mid + 1, r, i, j);
  }

public:
  int reversePairs(vector<int> &nums) {
    int n = nums.size();
    seg.resize(4 * n);

    vector<int> v = nums;
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans +=
          query(0, 0, n - 1,
                lower_bound(v.begin(), v.end(), 2LL * nums[i] + 1) - v.begin(),
                n - 1);
      update(0, 0, n - 1, lower_bound(v.begin(), v.end(), nums[i]) - v.begin());
    }
    return ans;
  }
};
