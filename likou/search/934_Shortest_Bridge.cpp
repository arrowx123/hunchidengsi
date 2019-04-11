struct node {
  int x;
  int y;
  int len;
};
class Solution {
private:
  vector<pair<int, int>> offset = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

public:
  int shortestBridge(vector<vector<int>> &A) {
    int m = A.size();
    int n = A[0].size();
    int ans = -1;

    vector<vector<int>> label(m, vector<int>(n, 0));

    int sign = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (A[i][j] == 1 && !label[i][j]) {
          label[i][j] = ++sign;
          stack<pair<int, int>> st;
          st.push({i, j});

          while (st.size()) {
            int x = st.top().first;
            int y = st.top().second;
            st.pop();

            for (int i = 0; i < offset.size(); i++) {
              int cx = x + offset[i].first;
              int cy = y + offset[i].second;

              if (cx >= 0 && cx < m && cy >= 0 && cy < n && A[cx][cy] &&
                  !label[cx][cy]) {
                label[cx][cy] = sign;
                st.push({cx, cy});
              }
            }
          }
          break;
        }
      }
      if (sign)
        break;
    }

    queue<node> que;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (label[i][j] == 1) {
          que.push({i, j, 0});
        }
      }
    }

    while (que.size()) {
      int x = que.front().x;
      int y = que.front().y;
      int len = que.front().len;
      que.pop();

      for (int i = 0; i < offset.size(); i++) {
        int cx = x + offset[i].first;
        int cy = y + offset[i].second;

        if (cx >= 0 && cx < m && cy >= 0 && cy < n && label[cx][cy] != 1) {
          if (A[cx][cy] == 1 && !label[cx][cy]) {
            ans = len;
            break;
          }

          label[cx][cy] = 1;
          que.push({cx, cy, len + 1});
        }
      }
      if (ans != -1)
        break;
    }

    return ans;
  }
};
