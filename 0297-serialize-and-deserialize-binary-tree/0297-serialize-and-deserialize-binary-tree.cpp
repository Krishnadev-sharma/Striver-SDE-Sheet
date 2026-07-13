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
    void dfs(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "N,";
            return;
        }
        s += to_string(root->val) + ",";
        dfs(root->left, s);
        dfs(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        dfs(root, s);
        return s;
    }
    TreeNode* build(string& data,int &i) {
        if (i >= data.size()) {
            return NULL;
        }
        if (data[i] == 'N') {
             i += 2;
            return NULL;
        }
        string val = "";
        while (data[i] != ',') {
            val += data[i];
            i++;
        }
        i++;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = build(data, i);
        root->right = build(data, i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return build(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));