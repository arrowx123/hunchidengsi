// 815_Bus_Routes
// bfs
class Solution {
private:
  bool isConnected(vector<int> v1, vector<int> v2) {
    int m = v1.size();
    int n = v2.size();

    int i = 0, j = 0;
    while (i < m && j < n) {
      if (v1[i] == v2[j])
        return true;
      if (v1[i] < v2[j])
        i++;
      else
        j++;
    }
    return false;
  }

public:
  int numBusesToDestination(vector<vector<int>> &routes, int S, int T) {
    if (S == T)
      return 0;

    int m = routes.size();
    for (int i = 0; i < m; i++)
      sort(routes[i].begin(), routes[i].end());

    unordered_map<int, vector<int>> umap;
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        if (isConnected(routes[i], routes[j])) {
          umap[i].push_back(j);
          umap[j].push_back(i);
        }
      }
    }

    queue<pair<int, int>> que;
    unordered_set<int> target;
    unordered_set<int> seen;
    for (int i = 0; i < m; i++) {
      int n = routes[i].size();
      for (int j = 0; j < n; j++) {
        if (routes[i][j] == S) {
          que.push({i, 1});
          seen.insert(i);
          break;
        }
      }
      for (int j = 0; j < n; j++) {
        if (routes[i][j] == T) {
          target.insert(i);
          break;
        }
      }
    }

    while (que.size()) {
      int route = que.front().first;
      int dis = que.front().second;
      que.pop();

      if (target.count(route))
        return dis;

      for (int i = 0; i < umap[route].size(); i++) {
        if (seen.count(umap[route][i]))
          continue;
        que.push({umap[route][i], dis + 1});
      }
    }
    return -1;
  }
};
