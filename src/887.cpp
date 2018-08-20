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
  vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
    int sum1 = 0;
    int sum2 = 0;

    unordered_set<int> usa;
    unordered_set<int> usb;

    for (int i = 0; i < (int)A.size(); i++) {
      sum1 += A[i];
      usa.insert(A[i]);
    }
    for (int i = 0; i < (int)B.size(); i++) {
      sum2 += B[i];
      usb.insert(B[i]);
    }

    int diff = (sum2 - sum1) / 2;
    cout << diff << endl;
    vector<int> ans;

    for (int i = 0; i < (int)A.size(); i++) {
      cout << A[i] << " " << A[i] + diff << endl;
      cout << usb.count(A[i] + diff) << endl;
      if (usb.find(A[i] + diff) != usb.end()) {
        cout << "inside" << endl;
        ans.push_back(A[i]);
        ans.push_back(A[i] + diff);
        break;
      }
    }
    cout << ans[0] << " " << ans[1] << endl;
    return ans;
  }
};

int main() {
  vector<int> A = {1, 2, 5};
  vector<int> B = {2, 4};
  Solution solution = Solution();
  solution.fairCandySwap(A, B);
  return 0;
}
