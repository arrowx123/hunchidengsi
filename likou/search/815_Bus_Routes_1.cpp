// 815_Bus_Routes
// bfs
// stop -> route -> stop
class Solution {
public:
  int numBusesToDestination(vector<vector<int>> &routes, int S, int T) {
    if (S == T)
      return 0;

    unordered_map<int, vector<int>> umap;
    int m = routes.size();

    for (int i = 0; i < m; i++) {
      int n = routes[i].size();
      for (int j = 0; j < n; j++) {
        umap[routes[i][j]].push_back(i);
      }
    }

    queue<int> que;
    unordered_set<int> seenStop;
    unordered_set<int> seenRoute;

    que.push(S);
    seenStop.insert(S);

    int ans = 0;
    int size = 0;
    int cnt = 0;
    while (que.size()) {
      if (size == cnt) {
        size = que.size();
        ans++;
        cnt = 0;
      }
      cnt++;

      int stop = que.front();
      que.pop();
      for (int i = 0; i < umap[stop].size(); i++) {
        int route = umap[stop][i];
        if (seenRoute.count(route))
          continue;
        seenRoute.insert(route);

        for (int j = 0; j < routes[route].size(); j++) {
          int newStop = routes[route][j];
          if (seenStop.count(newStop))
            continue;
          seenStop.insert(newStop);
          if (newStop == T)
            return ans;

          que.push(newStop);
        }
      }
    }
    return -1;
  }
};
