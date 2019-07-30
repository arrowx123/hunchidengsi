// 295_Find_Median_from_Data_Stream
// heap
class MedianFinder {
private:
  priority_queue<int, vector<int>, greater<int>> minH;
  priority_queue<int, vector<int>, less<int>> maxH;

public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    minH.push(num);
    maxH.push(minH.top());
    minH.pop();

    if (minH.size() < maxH.size()) {
      minH.push(maxH.top());
      maxH.pop();
    }
    return;
  }

  double findMedian() {
    if (minH.size() == maxH.size())
      return ((double)minH.top() + maxH.top()) / 2;
    return minH.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
