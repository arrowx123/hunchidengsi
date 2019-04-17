/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the
 * cell.
 *     // Returns false if the cell in front is blocked and robot stays in the
 * current cell. bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
private:
  set<pair<int, int>> uset;
  int d = 0;
  vector<pair<int, int>> offset = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  void dfs(int x, int y, Robot &robot) {

    uset.insert({x, y});
    robot.clean();

    for (int i = 0; i < 4; i++) {
      int newX = x + offset[d].first;
      int newY = y + offset[d].second;

      if (!uset.count({newX, newY}) && robot.move()) {
        dfs(newX, newY, robot);
      }
      robot.turnRight();
      d = (d + 1) % 4;
    }
    robot.turnRight();
    robot.turnRight();
    robot.move();
    robot.turnRight();
    robot.turnRight();
    return;
  }

public:
  void cleanRoom(Robot &robot) {
    dfs(0, 0, robot);
    return;
  }
};
