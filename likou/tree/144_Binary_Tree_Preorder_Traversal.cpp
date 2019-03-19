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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while(s.size()){
            TreeNode* cnode = s.top();
            s.pop();
            
            if(!cnode)
                continue;
            
            ans.push_back(cnode->val);
            s.push(cnode->right);
            s.push(cnode->left);
        }
        return ans;
    }
};
