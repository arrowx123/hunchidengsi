// 307_Range_Sum_Query
// segment_tree
class NumArray {
private:
  vector<int> segmentTree;
  int n;
  int build(int idx, int start, int end, vector<int> &v) {
    if (start == end) {
      return segmentTree[idx] = v[start];
    }

    int mid = (start + end) / 2;
    int l = build(idx * 2 + 1, start, mid, v);
    int r = build(idx * 2 + 2, mid + 1, end, v);
    return segmentTree[idx] = l + r;
  }

  void update(int idx, int start, int end, int pos, int val) {
    if (start == end) {
      segmentTree[idx] = val;
      return;
    }

    int mid = (start + end) / 2;
    if (pos <= mid)
      update(idx * 2 + 1, start, mid, pos, val);
    else
      update(idx * 2 + 2, mid + 1, end, pos, val);
    segmentTree[idx] = segmentTree[idx * 2 + 1] + segmentTree[idx * 2 + 2];
    return;
  }

  int rangeQuery(int idx, int start, int end, int l, int r) {
    if (l > end || r < start)
      return 0;
    if (l <= start && r >= end)
      return segmentTree[idx];

    int mid = (start + end) / 2;
    int p1 = rangeQuery(idx * 2 + 1, start, mid, l, r);
    int p2 = rangeQuery(idx * 2 + 2, mid + 1, end, l, r);
    return p1 + p2;
  }

public:
  NumArray(vector<int> &nums) {
    n = nums.size();
    segmentTree.resize(n * 4);
    if (n)
      build(0, 0, n - 1, nums);
  }

  void update(int i, int val) { update(0, 0, n - 1, i, val); }

  int sumRange(int i, int j) { return rangeQuery(0, 0, n - 1, i, j); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
