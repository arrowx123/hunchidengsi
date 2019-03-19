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

    void dfs_encode(TreeNode* node, string& ans){
        if(!node){
            ans += "()";
            return;
        }
        
        ans += "(";
        ans += to_string(node->val);
        dfs_encode(node->left, ans);
        dfs_encode(node->right, ans);
        ans += ")";
        return;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        dfs_encode(root, ans);
        return ans;
    }

    TreeNode* dfs_decode(string& data, int& pos){
        pos ++;
        string tmp = "";
        while(isdigit(data[pos]) || data[pos] == '-')
            tmp += data[pos ++];
        
        TreeNode* node = nullptr;
        if(tmp.size()){
            node = new TreeNode(stoi(tmp));
            node->left = dfs_decode(data, pos);
            node->right = dfs_decode(data, pos);
        }
        
        pos ++;
        return node;    
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size())
            return nullptr;
        
        int pos = 0;
        return dfs_decode(data, pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
