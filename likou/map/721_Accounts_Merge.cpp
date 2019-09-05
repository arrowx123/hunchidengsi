// 721_Accounts_Merge
// map
// O(Alog(A)), A = accounts.size() * accounts[i].size() * accounts[i][j].size()
class Solution {
private:
  int id = 0;
  unordered_map<int, int> parent;
  unordered_map<string, string> email2Name;
  unordered_map<string, int> email2Id;

  void uni(string e1, string e2) {
    int id1 = email2Id[e1];
    int id2 = email2Id[e2];
    parent[findP(id1)] = findP(id2);
  }

  int findP(int idx) {
    if (parent[idx] == idx)
      return idx;
    return parent[idx] = findP(parent[idx]);
  }

public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int n = accounts.size();
    for (int i = 0; i < n; i++) {
      string name = accounts[i][0];
      for (int j = 1; j < accounts[i].size(); j++) {
        string email = accounts[i][j];
        email2Name[email] = name;
        if (!email2Id.count(email)) {
          email2Id[email] = id;
          parent[id] = id;
          id++;
        }
        uni(email, accounts[i][1]);
      }
    }

    unordered_map<int, vector<string>> id2Email;
    vector<vector<string>> ans;
    for (auto tuple : email2Id)
      id2Email[findP(tuple.second)].push_back(tuple.first);
    for (auto tuple : id2Email) {
      vector<string> v = tuple.second;
      sort(v.begin(), v.end());
      v.insert(v.begin(), email2Name[v[0]]);
      ans.push_back(v);
    }
    return ans;
  }
};
