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
class Codec {
private:
    vector<vector<int>> ans;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root)
            return ans;
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(que.size()){
            for(int i = 0; i < que.size(); i ++){
                TreeNode* node = que.front();
                que.pop();
                
                if(!node){
                    ans += "null";
                }
                else{
                    ans += to_string(node->val);
                    que.push(node->left);
                    que.push(node->right);
                }
                ans += " ";
            }
        }
        cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size())
            return nullptr;
        
        vector<string> vals;
        string tmp = "";
        for(int i = 0; i < data.size(); i ++){
            if(data[i] == ' '){
                vals.push_back(tmp);
                tmp = "";
            }
            else{
                tmp += data[i];
            }
        }
        
        for(int i = 0; i < vals.size(); i ++){
            cout << vals[i] << " ";
        }
        cout << endl;
        
        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> que;
        que.push(root);
        int pos = 1;
        
        while(que.size()){
            for(int i = 0; i < que.size(); i ++){
                TreeNode* cnode = que.front();
                que.pop();

                if(!isalpha(vals[pos][0])){
                    cnode->left = new TreeNode(stoi(vals[pos]));
                    que.push(cnode->left);
                }
                pos ++;
                if(!isalpha(vals[pos][0])){
                    cnode->right = new TreeNode(stoi(vals[pos]));
                    que.push(cnode->right);
                }
                pos ++;
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
