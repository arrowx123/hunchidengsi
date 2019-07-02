// 4_Median_of_Two_Sorted_Arrays
// bs
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();

    if (!m)
      return n % 2 ? nums2[n / 2]
                   : (double(nums2[n / 2]) + nums2[n / 2 - 1]) / 2;
    if (!n)
      return m % 2 ? nums1[m / 2]
                   : (double(nums1[m / 2]) + nums1[m / 2 - 1]) / 2;

    int l = 0, r = m;
    int n11, n12, n21, n22;
    while (true) {
      int i = (l + r) / 2;
      int j = (m + n + 1) / 2 - i;

      if (j < 0)
        r--;
      else if (j > n)
        l++;
      else {
        n11 = (i - 1 >= 0 && i - 1 < m ? nums1[i - 1] : INT_MIN);
        n12 = (i >= 0 && i < m ? nums1[i] : INT_MAX);
        n21 = (j - 1 >= 0 && j - 1 < n ? nums2[j - 1] : INT_MIN);
        n22 = (j >= 0 && j < n ? nums2[j] : INT_MAX);

        if (n11 <= n22 && n21 <= n12) {
          if ((m + n) % 2)
            return max(n11, n21);
          return ((double)max(n11, n21) + min(n12, n22)) / 2;
        } else if (n11 > n22)
          r = i - 1;
        else
          l = i + 1;
      }
    }
  }
};
