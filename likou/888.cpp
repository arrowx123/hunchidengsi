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
  TreeNode *create(const vector<int> &pre, const vector<int> &post, int l0,
                   int l1, int N) {
    cout << l0 << " " << l1 << " " << N << endl;
		if (!N)
			return NULL;
    TreeNode *root = new TreeNode(pre[l0]);
    if (N == 1)
      return root;

    l0++;
    int i = 0;
    for (; i < N; i++) {
      if (pre[l0] == post[l1 + i])
        break;
    }

    root->left = create(pre, post, l0, l1, i + 1);
    root->right = create(pre, post, l0 + i + 1, l1 + i + 1, N - i - 2);
    return root;
  }

  TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
    TreeNode *ans = create(pre, post, 0, 0, (int)pre.size());
    return ans;
  }
};

int main() {
  vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
  vector<int> post = {4, 5, 2, 6, 7, 3, 1};

  Solution solution = Solution();
  solution.constructFromPrePost(pre, post);
  return 0;
}
