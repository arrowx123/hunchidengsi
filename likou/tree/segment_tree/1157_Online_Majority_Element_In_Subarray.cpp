// 1157_Online_Majority_Element_In_Subarray
// query: O(log(n)^2)
// build: O(nlog(n))
// segment tree
class MajorityChecker {
private:
  int threshold;
  vector<int> arr;
  vector<int> segT;
  unordered_map<int, vector<int>> umap;

  int build_tree(int idx, int l, int r) {
    if (l == r)
      return segT[idx] = arr[l];
    segT[idx] = -1;
    int mid = (l + r) / 2;
    int lt = build_tree(idx * 2 + 1, l, mid);
    int rt = build_tree(idx * 2 + 2, mid + 1, r);
    if (count(lt, l, r) * 2 > r - l + 1)
      segT[idx] = lt;
    if (count(rt, l, r) * 2 > r - l + 1)
      segT[idx] = rt;
    return segT[idx];
  }

  int query(int idx, int l, int r, int lq, int rq) {
    if (rq < l || lq > r)
      return -1;
    if (lq <= l && rq >= r)
      return segT[idx];

    int mid = (l + r) / 2;
    int ret = -1;
    int lt = query(idx * 2 + 1, l, mid, lq, rq);
    int rt = query(idx * 2 + 2, mid + 1, r, lq, rq);
    if (count(lt, lq, rq) * 2 > rq - lq + 1)
      ret = lt;
    if (count(rt, lq, rq) * 2 > rq - lq + 1)
      ret = rt;
    return ret;
  }

  int count(int num, int l, int r) {
    vector<int> &v = umap[num];
    return upper_bound(v.begin(), v.end(), r) -
           lower_bound(v.begin(), v.end(), l);
  }

public:
  MajorityChecker(vector<int> &arr) {
    this->arr = arr;
    segT.resize(arr.size() * 4);
    for (int i = 0; i < arr.size(); i++)
      umap[arr[i]].push_back(i);
    build_tree(0, 0, arr.size() - 1);
  }

  int query(int left, int right, int threshold) {
    this->threshold = threshold;
    int ret = query(0, 0, arr.size() - 1, left, right);
    if (ret == -1 || count(ret, left, right) < threshold)
      return -1;
    return ret;
  }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
