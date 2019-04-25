// 253_Meeting_Rooms_II
// sort
class Solution {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    int ans = 0;
    vector<int> start;
    vector<int> end;

    for (int i = 0; i < intervals.size(); i++) {
      start.push_back(intervals[i][0]);
      end.push_back(intervals[i][1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0;
    int j = 0;
    int used = 0;
    while (i < start.size()) {
      if (start[i] >= end[j]) {
        used--;
        j++;
      } else {
        used++;
        i++;
      }
      ans = max(ans, used);
    }
    return ans;
  }
};
