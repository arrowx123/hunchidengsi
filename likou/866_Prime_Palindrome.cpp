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
private:
  bool isprime(int n) {
		if(n == 1)
			return false;
    int upper = sqrt(n) + 1;
    for (int i = 2; i < upper; i++) {
      if (n % i == 0)
        return false;
    }
    return true;
  }

public:
  int primePalindrome(int N) {
    int ans = -1;
    for (int d = 1; d <= 5; d++) {
      for (int root = pow(10, d - 1); root < pow(10, d); root++) {
        int num = root;
        int tmp = root / 10;
        while (tmp) {
          num = num * 10 + tmp % 10;
          tmp /= 10;
        }
        cout << "num: " << num << endl;

        if (num > N && isprime(num)) {
          ans = num;
          break;
        }
      }
      if (ans != -1)
        break;
    }
		if(N < 11)
			ans = min(ans, 11);
    return ans;
  }
};
int main() {
  int N = 1;
  Solution solution;
  cout << solution.primePalindrome(N);
  return 0;
}
