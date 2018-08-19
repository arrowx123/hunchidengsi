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
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    vector<vector<int>> ans;

    int step = 1;
    int sign = 1;
    ans.push_back({r0, c0});

    while (true) {
      for (int i = 0; i < step; i++) {
        c0 += sign;

        if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
          ans.push_back({r0, c0});
        }
      }
			for (int i = 0; i < step; i++) {
        r0  += sign;

        if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
          ans.push_back({r0, c0});
        }
      }
			step ++;
			sign *= -1;
			if((int)ans.size() == R * C)
				break;
    }

//		for(auto ele: ans){
//			cout << ele.front() << " " << ele.back() << endl;
//		}
    return ans;
  }
};
int main() {
  int R = 5;
  int C = 6;
  int r0 = 1;
  int c0 = 4;
  Solution solution = Solution();
  solution.spiralMatrixIII(R, C, r0, c0);

  return 0;
}
