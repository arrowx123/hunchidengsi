/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
  int findSameChar(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] == s2[i])
        cnt++;
    }
    return cnt;
  }

public:
  void findSecretWord(vector<string> &wordlist, Master &master) {
    unordered_set<string> used;
    int n = wordlist.size();
    vector<string> list = wordlist;

    for (int x = 0; x < 10; x++) {
      int pos = list.size() / 2;
      int match = master.guess(list[pos]);
      used.insert(list[0]);

      vector<string> newList;
      for (int i = 0; i < list.size(); i++) {
        if (match == findSameChar(list[i], list[pos]))
          newList.push_back(list[i]);
      }
      list = newList;
      if (!newList.size())
        break;
    }
    return;
  }
};
