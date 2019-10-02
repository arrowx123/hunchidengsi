// 85_Maximal_Rectangle
// O(mn)
// stack
class Solution {
private:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> st;
    st.push(-1);
    int ret = 0;

    for (int i = 0; i < heights.size(); i++) {
      while (st.top() != -1 && heights[i] < heights[st.top()]) {
        int height = heights[st.top()];
        st.pop();
        ret = max(ret, height * (i - 1 - st.top()));
      }
      st.push(i);
    }

    while (st.top() != -1) {
      int height = heights[st.top()];
      st.pop();
      ret = max(ret, height * ((int)heights.size() - 1 - st.top()));
    }

    return ret;
  }

public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int m = matrix.size();
    if (!m)
      return 0;
    int n = matrix[0].size();
    int ret = 0;
    vector<int> dp(n);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '1')
          dp[j]++;
        else
          dp[j] = 0;
      }
      ret = max(ret, largestRectangleArea(dp));
    }
    return ret;
  }
};
