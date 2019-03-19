// iteration

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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        
        if(!root)
            return ans;
        
        TreeNode* cnode = root;
        while(s.size() || cnode){
            if(!cnode){
                cnode = s.top();
                s.pop();
                ans.push_back(cnode->val);
                cnode = cnode->right;
            }
            else{
                s.push(cnode);
                cnode = cnode->left;
            }
        }
        return ans;
    }
};
