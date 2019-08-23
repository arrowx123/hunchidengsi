// 84_Largest_Rectangle_in_Histogram
// stack
// O(n)
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    if (heights.empty())
      return 0;

    stack<int> st;
    st.push(-1);

    int ans = INT_MIN;
    for (int i = 0; i < heights.size(); i++) {
      while (st.size() > 1 && heights[i] < heights[st.top()]) {
        int height = heights[st.top()];
        st.pop();
        ans = max(ans, (i - 1 - st.top()) * height);
      }
      st.push(i);
    }

    while (st.size() > 1) {
      int height = heights[st.top()];
      st.pop();
      ans = max(ans, ((int)heights.size() - 1 - st.top()) * height);
    }
    return ans;
  }
};

// segment tree + dc
// worst O(nlog(n))
// average O(log(n)log(n))
class Solution {
private:
  vector<int> v;
  vector<int> segT;
  int build(int pos, int l, int r) {
    if (l + 1 == r)
      return segT[pos] = l;
    int mid = (l + r) / 2;
    int left = build(pos * 2 + 1, l, mid);
    int right = build(pos * 2 + 2, mid, r);
    return segT[pos] = v[left] < v[right] ? left : right;
  }

  int query(int pos, int l, int r, int i, int j) {
    if (i >= r || j <= l)
      return INT_MAX;
    if (i <= l && j >= r)
      return segT[pos];

    int mid = (l + r) / 2;
    int left = query(pos * 2 + 1, l, mid, i, j);
    int right = query(pos * 2 + 2, mid, r, i, j);
    if (left == INT_MAX)
      return right;
    if (right == INT_MAX)
      return left;
    return v[left] < v[right] ? left : right;
  }

  int getSize(int i, int j) {
    if (i >= j)
      return 0;
    int idx = query(0, 0, v.size(), i, j);
    return max((j - i) * v[idx], max(getSize(i, idx), getSize(idx + 1, j)));
  }

public:
  int largestRectangleArea(vector<int> &heights) {
    if (heights.empty())
      return 0;

    v = heights;
    segT.resize(v.size() * 4);
    build(0, 0, v.size());
    return getSize(0, v.size());
  }
};
