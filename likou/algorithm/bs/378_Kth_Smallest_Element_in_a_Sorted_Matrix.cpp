// 378_Kth_Smallest_Element_in_a_Sorted_Matrix
// bs
class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int l = matrix[0][0];
    int r = matrix[n - 1][n - 1];

    while (l < r) {
      int mid = (l + r) / 2;
      int cnt = 0;
      for (int i = 0; i < n; i++)
        cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) -
               matrix[i].begin();

      if (cnt < k)
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
};

// bs
class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int l = matrix[0][0];
    int r = matrix[n - 1][n - 1];

    while (l < r) {
      int mid = (l + r) / 2;
      int cnt = 0;

      int i = 0, j = n - 1;
      while (i < n && j >= 0) {
        if (matrix[i][j] <= mid) {
          cnt += j + 1;
          i++;
        } else
          j--;
      }

      if (cnt < k)
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
};
