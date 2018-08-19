#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    int len = people.size();
    int i = 0;
    int j = len - 1;
    int ans = 0;
    sort(people.begin(), people.end());

    while (i < j) {
      ans++;
      if (people[j] + people[i] <= limit) {
        i++;
      }
      j--;
    }
    if (i == j)
      ans++;

    return ans;
  }
};

int main() {
  vector<int> people = {3, 5, 3, 4};
  int limit = 5;
  Solution solution = Solution();
  cout << solution.numRescueBoats(people, limit);

  return 0;
}
