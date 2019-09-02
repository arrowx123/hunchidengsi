// 432_All_O_one_Data_Structure
// linked_list
typedef pair<int, unordered_set<string>> pis;

class AllOne {
private:
  list<pis> l;
  unordered_map<string, list<pis>::iterator> k2it;

public:
  /** Initialize your data structure here. */
  AllOne() {
    l.clear();
    k2it.clear();
  }

  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1.
   */
  void inc(string key) {
    if (!k2it.count(key)) {
      if (l.size() && l.back().first == 1) {
        l.back().second.insert(key);
        k2it[key] = prev(l.end());
      } else {
        auto insert = l.insert(l.end(), {1, {key}});
        k2it[key] = insert;
      }
    } else {
      auto it = k2it[key];
      int val = it->first;
      if (it != l.begin() && prev(it)->first == val + 1) {
        (prev(it)->second).insert(key);
        k2it[key] = prev(it);
      } else {
        auto insert = l.insert(it, {val + 1, {key}});
        k2it[key] = insert;
      }

      (it->second).erase(key);
      if ((it->second).empty())
        l.erase(it);
    }
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the
   * data structure. */
  void dec(string key) {
    if (!k2it.count(key))
      return;
    auto it = k2it[key];
    auto nex = next(it);
    int val = it->first;

    (it->second).erase(key);
    if ((it->second).empty())
      l.erase(it);
    if (val == 1) {
      k2it.erase(key);
      return;
    }

    if (nex != l.end() && nex->first == val - 1) {
      (nex->second).insert(key);
      k2it[key] = nex;
    } else {
      auto insert = l.insert(nex, {val - 1, {key}});
      k2it[key] = insert;
    }
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    if (l.size())
      return *l.front().second.begin();
    return "";
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    if (l.size())
      return *l.back().second.begin();
    return "";
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
