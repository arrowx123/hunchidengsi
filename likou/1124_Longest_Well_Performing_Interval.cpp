// 1124_Longest_Well_Performing_Interval
// map
// O(nlog(n))
class Solution {
public:
  int longestWPI(vector<int> &hours) {
    map<int, int> m;
    m[0] = -1;
    int cnt = 0, ans = 0;

    for (int i = 0; i < hours.size(); i++) {
      cnt += hours[i] > 8 ? -1 : 1;
      if (auto it = m.upper_bound(cnt); it != m.end())
        ans = max(ans, i - it->second);
      else
        m.insert({cnt, i});
    }
    return ans;
  }
};
// vector
// O(n)
class Solution {
public:
  int longestWPI(vector<int> &hours) {
    int ans = 0, cnt = 0;
    vector<int> v = {0};

    for (int i = 0; i < hours.size(); i++) {
      cnt += hours[i] > 8 ? -1 : 1;
      if (cnt < 0)
        ans = max(ans, i + 1);
      else if (1 + cnt < v.size())
        ans = max(ans, i - v[1 + cnt]);
      else if (cnt == v.size())
        v.push_back(i);
    }
    return ans;
  }
};
