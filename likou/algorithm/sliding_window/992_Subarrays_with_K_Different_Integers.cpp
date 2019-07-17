// 992_Subarrays_with_K_Different_Integers
// sliding_window

// 20190716
class Solution {
public:
  int subarraysWithKDistinct(vector<int> &A, int K) {
    int l1 = 0, l2 = 0;

    unordered_map<int, int> cnt1;
    unordered_map<int, int> cnt2;
    int ans = 0;

    for (int i = 0; i < A.size(); i++) {
      cnt1[A[i]]++;
      cnt2[A[i]]++;

      while (cnt1.size() > K) {
        cnt1[A[l1]]--;
        if (!cnt1[A[l1]])
          cnt1.erase(A[l1]);
        l1++;
      }

      while (cnt2.size() >= K) {
        cnt2[A[l2]]--;
        if (!cnt2[A[l2]])
          cnt2.erase(A[l2]);
        l2++;
      }

      ans += l2 - l1;
    }
    return ans;
  }
};

// 20190504
class Solution {
public:
  int subarraysWithKDistinct(vector<int> &A, int K) {
    unordered_map<int, int> count;
    int n = A.size();
    int ans = 0;
    int l = 0;
    int r = 0;
    while (r < n) {
      if (count.size() < K) {
        count[A[r]]++;
        r++;
      } else if (count.size() == K) {
        int i = r;
        for (; i < n; i++) {
          if (!count.count(A[i]))
            break;
        }
        ans += (i - r + 1);
        count[A[l]]--;
        if (!count[A[l]])
          count.erase(A[l]);
        l++;
      }
    }
    while (l < n) {
      if (count.size() == K)
        ans++;
      else
        break;

      count[A[l]]--;
      if (!count[A[l]])
        count.erase(A[l]);
      l++;
    }
    return ans;
  }
};
