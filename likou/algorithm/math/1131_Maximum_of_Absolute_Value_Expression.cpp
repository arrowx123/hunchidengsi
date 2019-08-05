// 1131_Maximum_of_Absolute_Value_Expression
// math
class Solution {
public:
  int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2) {
    vector<vector<int>> v;
    int n = arr1.size();

    vector<int> tmp;
    for (int i = 0; i < n; i++)
      tmp.push_back(arr1[i] + arr2[i] + i);
    v.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < n; i++)
      tmp.push_back(arr1[i] + arr2[i] - i);
    v.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < n; i++)
      tmp.push_back(arr1[i] - arr2[i] + i);
    v.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < n; i++)
      tmp.push_back(arr1[i] - arr2[i] - i);
    v.push_back(tmp);
    tmp.clear();

    int ans = 0;
    for (int i = 0; i < v.size(); i++)
      ans = max(ans, *max_element(v[i].begin(), v[i].end()) -
                         *min_element(v[i].begin(), v[i].end()));
    return ans;
  }
};
