// 863_All_Nodes_Distance_K_in_Binary_Tree
// tree
// bfs
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
  queue<TreeNode *> que;
  unordered_set<TreeNode *> used;
  unordered_map<TreeNode *, TreeNode *> pa;

  void traverse(TreeNode *p, TreeNode *n) {
    if (!n)
      return;
    pa[n] = p;
    traverse(n, n->left);
    traverse(n, n->right);
    return;
  }

  void push_to_queue(TreeNode *n) {
    if (!n)
      return;
    if (used.count(n))
      return;
    used.insert(n);
    que.push(n);
    return;
  }

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    traverse(nullptr, root);
    vector<int> ans;
    int dist = 0;

    push_to_queue(target);
    while (que.size() && dist <= K) {
      int size = que.size();
      for (int i = 0; i < size; i++) {
        TreeNode *n = que.front();
        que.pop();

        if (dist == K)
          ans.push_back(n->val);
        push_to_queue(pa[n]);
        push_to_queue(n->left);
        push_to_queue(n->right);
      }
      dist++;
    }
    return ans;
  }
};

// tree traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *root, *target;
    int K;
    vector<int> ans;

    int dfs(TreeNode *n){
        if(!n) return -1;
        if(n == target){
            add(target, 0);
            return 0;
        }

        int l = dfs(n->left), r = dfs(n->right);
        if(l != -1){
            if(l + 1== K) ans.push_back(n->val);
            else add(n->right, l + 2);
            return l + 1;
        }
        else if(r != -1){
            if(r + 1 == K) ans.push_back(n->val);
            else add(n->left, r + 2);
            return r + 1;
        }
        return -1;
    }

    void add(TreeNode *n, int dist){
        if(!n) return;
        if(dist > K) return;
        if(dist == K) ans.push_back(n->val);
        add(n->left, dist + 1);
        add(n->right, dist + 1);
        return;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        this->root = root;
        this->target = target;
        this->K = K;
        dfs(root);
        return ans;
    }
};
