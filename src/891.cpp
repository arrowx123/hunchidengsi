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
    int sumSubseqWidths(vector<int>& A) {
			int len = (int)A.size();
			int ans = 0;
			int mod = 1e9 + 7;

			sort(A.begin(), A.end());
			vector<long> pow = {1};
			
			for(int i = 1; i < len; i ++){
				 pow.push_back(pow[i - 1] * 2 % mod);
			}

			for(int i = 0; i < len; i ++){
				ans = (ans + ((pow[i] - 1) - (pow[len - i - 1] - 1)) * A[i] % mod) % mod;
			}
			ans = (ans + mod) % mod;

			return ans;

    }
};


int main() {
	vector<int> A = {2, 1, 3};
  Solution solution = Solution();
  cout << solution.sumSubseqWidths(A);
  return 0;
}
