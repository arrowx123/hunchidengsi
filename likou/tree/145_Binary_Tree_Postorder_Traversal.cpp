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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;

        if(!root)
            return ans;

        TreeNode* cnode = root;
        while(s.size() || cnode){
            // cout << s.top() << endl;
            if(cnode){
                if(cnode->right)
                    s.push(cnode->right);
                s.push(cnode);
                cnode = cnode->left;
            }
            else{
                cnode = s.top();
                s.pop();

                if(s.size() && s.top() == cnode->right){
                    s.pop();
                    s.push(cnode);
                    cnode = cnode->right;
                }
                else{
                    ans.push_back(cnode->val);
                    cnode = NULL;
                }
            }
        }
        return ans;
    }
};
