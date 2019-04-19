// greedy
class Solution {
public:
  string rearrangeString(string s, int k) {
    unordered_map<char, int> umap;
    int max_cnt = INT_MIN;
    for (int i = 0; i < s.size(); i++) {
      umap[s[i]]++;
      max_cnt = max(max_cnt, umap[s[i]]);
    }

    vector<pair<char, int>> v;
    for (auto ele : umap)
      v.push_back({ele.first, ele.second});

    auto cmp = [](pair<char, int> p1, pair<char, int> p2) {
      return p1.second > p2.second;
    };
    sort(v.begin(), v.end(), cmp);

    vector<vector<char>> buckets(max_cnt);
    int pos = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].second == max_cnt) {
        for (int j = 0; j < buckets.size(); j++) {
          buckets[j].push_back(v[i].first);
        }
      } else {
        int size = v[i].second;
        while (size) {
          buckets[pos].push_back(v[i].first);
          pos = (pos + 1) % (max_cnt - 1);
          size--;
        }
      }
    }

    string ans = "";
    for (int i = 0; i < buckets.size(); i++) {
      if (i != buckets.size() - 1 && buckets[i].size() < k)
        return "";
      for (auto c : buckets[i])
        ans += c;
    }
    return ans;
  }
};
