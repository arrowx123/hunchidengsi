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
