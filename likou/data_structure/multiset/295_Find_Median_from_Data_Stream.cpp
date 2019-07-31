// 295_Find_Median_from_Data_Stream
// multiset
class MedianFinder {
private:
  multiset<int> mset;
  multiset<int>::iterator l;
  multiset<int>::iterator r;

public:
  /** initialize your data structure here. */
  MedianFinder() { mset.clear(); }

  void addNum(int num) {
    mset.insert(num);
    if (mset.size() == 1) {
      l = mset.begin();
      r = mset.begin();
    } else {
      if (mset.size() % 2) {
        if (num >= *l && num < *r) {
          l++;
          r--;
        } else if (num >= *r)
          l++;
        else
          r--;
      } else {
        if (num >= *r)
          r++;
        else
          l--;
      }
    }
  }

  double findMedian() { return double(*l + *r) / 2; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
