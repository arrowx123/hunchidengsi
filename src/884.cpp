#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> uncommonFromSentences(string A, string B) {
    vector<string> t1;
    vector<string> t2;

    stringstream s1(A);
    stringstream s2(B);
    string tmp;
    while (s1 >> tmp)
      t1.push_back(tmp);
    while (s2 >> tmp)
      t2.push_back(tmp);

    unordered_map<string, int> um1;
    unordered_map<string, int> um2;

    for (int i = 0; i < (int)t1.size(); i++) {
      um1[t1[i]]++;
    }
    for (int i = 0; i < (int)t2.size(); i++) {
      um2[t2[i]]++;
    }

    vector<string> ans;
    for (auto it = um1.begin(); it != um1.end(); it++) {
      if (it->second == 1 && um2.count(it->first) == 0)
        ans.push_back(it->first);
    }
    for (auto it = um2.begin(); it != um2.end(); it++) {
      if (it->second == 1 && um1.count(it->first) == 0)
        ans.push_back(it->first);
    }
    return ans;
  }
};

int main() {
  string A = "this apple is sweet";
  string B = "this apple is sour";
  Solution solution = Solution();
  solution.uncommonFromSentences(A, B);

  return 0;
}
