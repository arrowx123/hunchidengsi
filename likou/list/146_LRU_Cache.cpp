// 146_LRU_Cache
// list
class LRUCache {
private:
  int cap;
  unordered_map<int, int> keyValue;
  unordered_map<int, list<int>::iterator> keyPos;
  list<int> myList;

public:
  LRUCache(int capacity) { cap = capacity; }

  int get(int key) {
    if (!keyValue[key])
      return -1;

    myList.erase(keyPos[key]);
    myList.push_front(key);
    keyPos[key] = myList.begin();
    return keyValue[key];
  }

  void put(int key, int value) {
    keyValue[key] = value;

    if (keyPos.count(key)) {
      myList.erase(keyPos[key]);
    }

    myList.push_front(key);
    keyPos[key] = myList.begin();

    if (myList.size() > cap) {
      int removeKey = myList.back();
      keyValue.erase(removeKey);
      keyPos.erase(removeKey);
      myList.pop_back();
    }
    return;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
