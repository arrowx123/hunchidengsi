// dfs
class Solution {
private:
  map<pair<string, string>, double> dp;
  unordered_map<string, vector<string>> conn;
  unordered_set<string> visited;
  double solve(string s1, string s2, double val) {
    if (dp.count({s1, s2})) {
      return val * dp[{s1, s2}];
    }

    double ans = -1;
    for (int i = 0; i < conn[s1].size(); i++) {
      if (!visited.count(conn[s1][i])) {
        visited.insert(conn[s1][i]);
        ans = solve(conn[s1][i], s2, val * dp[{s1, conn[s1][i]}]);

        if (ans != -1)
          break;
      }
    }
    return dp[{s1, s2}] = ans;
  }

public:
  vector<double> calcEquation(vector<pair<string, string>> equations,
                              vector<double> &values,
                              vector<pair<string, string>> queries) {

    for (int i = 0; i < equations.size(); i++) {
      string s1 = equations[i].first;
      string s2 = equations[i].second;
      double val = values[i];

      dp[{s1, s2}] = val;
      dp[{s2, s1}] = 1.0 / val;

      conn[s1].push_back(s2);
      conn[s2].push_back(s1);
    }

    vector<double> ans;
    for (int i = 0; i < queries.size(); i++) {
      visited.clear();
      ans.push_back(solve(queries[i].first, queries[i].second, 1));
    }
    return ans;
  }
};
