// 1072_Flip_Columns_For_Maximum_Number_of_Equal_Rows
// map
// O(mn)
class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    unordered_map<string, int> cnt;

    for (int i = 0; i < m; i++) {

      int flag = matrix[i][0];
      string tmp = "";
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == flag)
          tmp += '1';
        else
          tmp += '0';
      }
      cnt[tmp]++;
    }

    int ans = 0;
    for (auto &[key, val] : cnt)
      ans = max(ans, val);
    return ans;
  }
};
