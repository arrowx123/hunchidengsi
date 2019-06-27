// 297_Serialize_and_Deserialize_Binary_Tree
// recursion

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
public:
    void dfs(TreeNode* node, string& ans){
        if(!node)
            ans += "null ";
        else{
            ans += to_string(node->val) + " ";
            dfs(node->left, ans);
            dfs(node->right, ans);
        }
        return;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        dfs(root, ans);
        return ans;
    }
    
    TreeNode* dfs_decode(vector<string>& vals, int& pos){
        if(isalpha(vals[pos][0])){
            pos ++;
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(stoi(vals[pos ++]));
        node->left = dfs_decode(vals, pos);
        node->right = dfs_decode(vals, pos);
        
        return node;
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
        
        int pos = 0;
        return dfs_decode(vals, pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
