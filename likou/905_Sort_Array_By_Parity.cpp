#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <stack>
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
  vector<int> sortArrayByParity(vector<int> &A) {
    int len = A.size();
    vector<int> even;
    vector<int> odd;

    for (int i = 0; i < len; i++) {
      if (A[i] % 2 == 0)
        even.push_back(A[i]);
      else
        odd.push_back(A[i]);
    }
		for(int i = 0; i < (int)odd.size(); i ++){
			even.push_back(odd[i]);
		}
		return even;
  }
};
int main() {
  vector<int> A= {11, 3, 9, 5, 6, 4, 7};
	Solution solution;
	solution.sortArrayByParity(A);
  return 0;
}
