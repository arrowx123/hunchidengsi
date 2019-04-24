// 855_Exam_Room
// map
class ExamRoom {
private:
  set<int> myset;
  int N;

public:
  ExamRoom(int N) { this->N = N; }

  int seat() {
    if (!myset.size()) {
      myset.insert(0);
      return 0;
    } else {
      int last_pos = 0;
      set<int>::iterator it = myset.begin();

      int len = (*it) - 0;
      int target = 0;

      for (; it != myset.end(); it++) {
        int mid = (last_pos + (*it)) / 2;
        int dis = min(mid - last_pos, (*it) - mid);

        if (dis > len) {
          len = dis;
          target = mid;
        }
        last_pos = (*it);
      }

      if (N - 1 - last_pos > len) {
        len = N - 1 - last_pos;
        target = N - 1;
      }

      myset.insert(target);
      return target;
    }
  }

  void leave(int p) { myset.erase(p); }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
