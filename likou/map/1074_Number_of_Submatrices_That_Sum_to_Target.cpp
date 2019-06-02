// 1074_Number_of_Submatrices_That_Sum_to_Target
// map

class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 1; j < n; j++)
        matrix[i][j] += matrix[i][j - 1];
      for (int j = 0; j < n; j++)
        matrix[i][j] += (i > 0 ? matrix[i - 1][j] : 0);
    }

    unordered_map<int, int> cnt;
    for (int i = 0; i < m; i++) {
      for (int j = i; j < m; j++) {
        cnt.clear();
        cnt[0] = 1;
        for (int k = 0; k < n; k++) {
          int sum = matrix[j][k] - (i > 0 ? matrix[i - 1][k] : 0);
          ans += cnt[sum - target];
          cnt[sum]++;
        }
      }
    }

    return ans;
  }
};
