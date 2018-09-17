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
class StockSpanner {
private:
  stack<int> prices;
  stack<int> weights;

public:
  StockSpanner() {}

  int next(int price) {
    int weight = 1;
    while (!prices.empty() && prices.top() <= price) {
      weight += weights.top();
      weights.pop();
			prices.pop();
    }
    prices.push(price);
    weights.push(weight);
    return weight;
  }
};
int main() {
  vector<int> prices = {11, 3, 9, 5, 6, 4, 7};
  StockSpanner stockSpanner = StockSpanner();

  for (int i = 0; i < (int)prices.size(); i++) {
		cout << prices[i] << " ";
    cout << stockSpanner.next(prices[i]) << endl;
  }
  return 0;
}
