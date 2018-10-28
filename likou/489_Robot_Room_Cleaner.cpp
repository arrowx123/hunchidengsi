#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
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
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Node {
public:
  int val;
  Node *next;

  Node() {}

  Node(int _val, Node *_next) {
    val = _val;
    next = _next;
  }
};
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
class Robot {
public:
  // Returns true if the cell in front is open and robot moves into the cell.
  // Returns false if the cell in front is blocked and robot stays in the
  // current cell.
  bool move();

  // Robot will stay in the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
};
class Solution {
private:
  map<pair<int, int>, bool> v2;
  unordered_map<int, char> direction;
  pair<int, int> convert_to_pos(string curr) {
    int x = 0;
    int y = 0;
    int len = curr.size();
    for (int i = 0; i < len; i++) {
      if (curr[i] == 'u') {
        y += 1;
      } else if (curr[i] == 'd') {
        y -= 1;
      } else if (curr[i] == 'l') {
        x -= 1;
      } else if (curr[i] == 'r') {
        x += 1;
      }
    }
    return {x, y};
  }
  void dfs(string &curr, Robot &robot, int &di) {
    pair<int, int> relative_pos = convert_to_pos(curr);
    //		cout << relative_pos.first << " " << relative_pos.second <<
    // endl;
    if (!v2.count(relative_pos)) {
      v2[relative_pos] = true;
      robot.clean();
      for (int i = 0; i < 4; i++) {
        if (robot.move()) {
          curr += direction[di];
          dfs(curr, robot, di);
        }
        robot.turnLeft();
        di = (di + 1) % 4;
      }
    }
    robot.turnLeft();
    robot.turnLeft();
    robot.move();
    robot.turnLeft();
    robot.turnLeft();
    if (curr.size())
      curr.resize(curr.size() - 1);

    return;
  }

public:
  Solution() {
    direction[0] = 'u';
    direction[1] = 'l';
    direction[2] = 'd';
    direction[3] = 'r';
  }

  void cleanRoom(Robot &robot) {
    string curr = "";
    int di = 0;
    dfs(curr, robot, di);
    return;
  }
};
int main() {
  Robot robot;
  Solution solution;
  solution.cleanRoom(robot);
  return 0;
}
