// ufs
class Solution {
private:
  vector<int> parent;
  int getParent(int v) {
    if (parent[v] == v)
      return v;
    return parent[v] = getParent(parent[v]);
  }

public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> indegree(n + 1);
    vector<int> outdegree(n + 1);
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
      parent[i] = i;

    int target = -1;
    bool twoParent = false;
    for (int i = 0; i < edges.size(); i++) {
      int l = edges[i][0];
      int r = edges[i][1];

      indegree[r]++;
      outdegree[l]++;

      if (indegree[r] == 2) {
        target = r;
        twoParent = true;
      }
    }
    vector<int> ans;
    if (!twoParent) {
      for (int i = 0; i < edges.size(); i++) {
        int l = edges[i][0];
        int r = edges[i][1];

        if (getParent(l) == getParent(r)) {
          ans = {l, r};
          break;
        } else
          parent[getParent(l)] = parent[getParent(r)];
      }
    } else {
      vector<int> record;
      for (int i = 0; i < edges.size(); i++) {
        int l = edges[i][0];
        int r = edges[i][1];

        if (r == target) {
          record.push_back(l);
          if (record.size() == 1)
            parent[getParent(l)] = parent[getParent(r)];
        } else
          parent[getParent(l)] = parent[getParent(r)];
      }

      if (getParent(record[1]) == getParent(target))
        ans = {record[1], target};
      else
        ans = {record[0], target};
    }
    return ans;
  }
};
