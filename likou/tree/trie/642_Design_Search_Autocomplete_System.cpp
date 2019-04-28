// 642_Design_Search_Autocomplete_System
// trie
const int sigma = 27;
struct Node {
  bool end;
  int time;
  Node *children[sigma];
  Node() {
    end = false;
    time = 0;
    for (int i = 0; i < sigma; i++)
      children[i] = nullptr;
  }
};
class AutocompleteSystem {
private:
  Node *root;
  string sch;

  void build(string str, int time) {
    Node *node = root;
    for (int i = 0; i < str.size(); i++) {
      int ch = str[i] == ' ' ? 26 : str[i] - 'a';
      if (!node->children[ch])
        node->children[ch] = new Node();
      node = node->children[ch];
    }
    node->time = node->time + time;
    node->end = true;
  }

  void retrieveUtil(vector<pair<string, int>> &ret, string &pre, Node *node) {
    if (node->end) {
      ret.push_back({pre, node->time});
    }
    for (int i = 0; i < sigma; i++) {
      if (node->children[i]) {
        pre += i < 26 ? i + 'a' : ' ';
        retrieveUtil(ret, pre, node->children[i]);
        pre.pop_back();
      }
    }
  }

  vector<string> retrieve(string str) {
    Node *node = root;
    for (int i = 0; i < str.size(); i++) {
      int ch = str[i] == ' ' ? 26 : str[i] - 'a';
      if (!node->children[ch])
        return vector<string>{};
      node = node->children[ch];
    }

    vector<pair<string, int>> results;
    retrieveUtil(results, str, node);
    auto cmp = [](pair<string, int> p1, pair<string, int> p2) {
      if (p1.second != p2.second)
        return p1.second > p2.second;
      return p1.first.compare(p2.first) < 0;
    };
    sort(results.begin(), results.end(), cmp);

    vector<string> ans;
    for (int i = 0; i < min(3, (int)results.size()); i++) {
      ans.push_back(results[i].first);
    }
    return ans;
  }

public:
  AutocompleteSystem(vector<string> &sentences, vector<int> &times) {
    root = new Node();
    sch = "";

    int n = sentences.size();
    for (int i = 0; i < n; i++) {
      build(sentences[i], times[i]);
    }
  }

  vector<string> input(char c) {
    if (c == '#') {
      build(sch, 1);
      sch = "";
      return vector<string>{};
    }
    sch += c;
    return retrieve(sch);
  }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
