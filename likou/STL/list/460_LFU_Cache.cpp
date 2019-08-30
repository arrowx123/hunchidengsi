// 460_LFU_Cache
// list
class LFUCache {
private:
  int c;
  list<int> l;
  unordered_map<int, int> k2v, k2c;
  unordered_map<int, list<int>::iterator> k2it, c2it;

  void init() {
    c = 0;
    l.clear(), k2v.clear(), k2c.clear(), k2it.clear(), c2it.clear();
  }

  void increaseFreq(int key) {
    int count = k2c[key];
    auto it = c2it.find(count + 1);

    if (it == c2it.end())
      it = c2it.find(count);
    auto insert = l.insert(it->second, key);

    if (c2it[count] == k2it[key]) {
      auto nit = next(k2it[key]);
      if (nit == l.end() || k2c[*nit] != count)
        c2it.erase(count);
      else
        c2it[count] = nit;
    }

    l.erase(k2it[key]);
    k2it[key] = insert;
    k2c[key] = count + 1;
    c2it[count + 1] = insert;
  }

  void removeLast() {
    int key = l.back();
    int count = k2c[key];
    k2c.erase(key);
    k2v.erase(key);

    if (k2it[key] == c2it[count])
      c2it.erase(count);
    k2it.erase(key);
    l.pop_back();
  }

  void insert(int key, int value) {
    k2v[key] = value;
    k2c[key] = 0;

    auto it = c2it.find(0);
    auto insert = l.insert(it == c2it.end() ? l.end() : it->second, key);
    k2it[key] = insert;
    c2it[0] = insert;
  }

public:
  LFUCache(int c) {
    init();
    this->c = c;
  }

  int get(int key) {
    if (!k2v.count(key))
      return -1;
    increaseFreq(key);
    return k2v[key];
  }

  void put(int key, int value) {
    if (!this->c)
      return;
    if (k2v.count(key)) {
      k2v[key] = value;
      increaseFreq(key);
    } else {
      if (k2v.size() >= c)
        removeLast();
      insert(key, value);
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
