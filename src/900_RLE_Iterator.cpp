#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class RLEIterator {
private:
	queue<int> num;
	queue<int> cnt;
public:
    RLEIterator(vector<int> A) {
			int len = A.size();
			for(int i = 0; i < len; i ++){
				if(i % 2 == 0){
					cnt.push(A[i]);
				}
				else{
					num.push(A[i]);
				}
			}
    }

    int next(int n) {
			int ans = -1;
			while(n && num.size()){
				if(n < cnt.front())
				{
					cnt.front() -= n;
					n = 0;
					ans = num.front();
				}
				else if(n == cnt.front())
				{
					cnt.pop();
					ans = num.front();
					num.pop();
					n = 0;
				} 
				else{
					n -= cnt.front();
					cnt.pop();
					num.pop();
				}
			}
			return ans;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
int main() {
  return 0;
}
