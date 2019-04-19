// pq
class Solution {
public:
  string rearrangeString(string s, int k) {
    if (!k)
      return s;

    unordered_map<char, int> umap;
    int max_ = INT_MIN;
    for (int i = 0; i < s.size(); i++) {
      umap[s[i]]++;
    }

    priority_queue<pair<int, char>> pq;
    for (auto ele : umap) {
      pq.push({ele.second, ele.first});
    }

    string ans = "";
    while (pq.size()) {
      vector<pair<int, char>> v;
      int i = 0;
      for (; i < k && pq.size(); i++) {
        pair<int, char> pa = pq.top();
        pq.pop();

        ans += pa.second;
        if (--pa.first)
          v.push_back(pa);
      }

      if (i < k && v.size())
        return "";

      for (auto ele : v)
        pq.push(ele);
    }
    return ans;
  }
};
