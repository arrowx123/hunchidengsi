// 1029_Two_City_Scheduling
// greedy
class Solution {
public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    int ans = 0;
    for (int i = 0; i < costs.size(); i++) {
      ans += costs[i][0];
    }

    auto cmp = [](vector<int> v1, vector<int> v2) {
      return v1[1] - v1[0] < v2[1] - v2[0];
    };
    sort(costs.begin(), costs.end(), cmp);
    for (int i = 0; i < costs.size() / 2; i++) {
      ans -= costs[i][0];
      ans += costs[i][1];
    }
    return ans;
  }
};
