// pq
const double MAX = 1e13;
class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K) {
    vector<pair<double, int>> v;
    for (int i = 0; i < quality.size(); i++) {
      v.push_back({double(wage[i]) / quality[i], quality[i]});
    }

    auto cmp = [](pair<double, int> p1, pair<double, int> p2) {
      return p1.first < p2.first;
    };
    sort(v.begin(), v.end(), cmp);

    auto pqCmp = [](int b, int a) { return a > b; };
    priority_queue<int, vector<int>, decltype(pqCmp)> pq(pqCmp);

    int sum = 0;
    double ans = MAX;
    for (int i = 0; i < v.size(); i++) {
      sum += v[i].second;
      pq.push(v[i].second);

      if (pq.size() > K) {
        int qual = pq.top();
        pq.pop();
        sum -= qual;
      }

      if (pq.size() == K) {
        ans = min(ans, sum * v[i].first);
      }
    }
    return ans;
  }
};
