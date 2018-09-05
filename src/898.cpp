#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  int subarrayBitwiseORs(vector<int> &A) {
    int len = A.size();
    unordered_set<int> uset;
    unordered_set<int> ans;
		uset.insert(0);

    for (int i = 0; i < len; i++) {
			unordered_set<int> tmp_uset;
			for(auto ele: uset){
				tmp_uset.insert(A[i] | ele);
			}
			tmp_uset.insert(A[i]);
			uset = tmp_uset;
			ans.insert(uset.begin(), uset.end());
    }

    return ans.size();
  }
};
int main() {
	vector<int>	A = {1,2,4};
  Solution solution = Solution();
  cout << solution.subarrayBitwiseORs(A);
  return 0;
}
