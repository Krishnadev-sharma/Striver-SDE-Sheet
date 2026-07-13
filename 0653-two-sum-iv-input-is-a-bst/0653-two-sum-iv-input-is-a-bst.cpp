/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Bst{
      stack<TreeNode*> st;
      bool reverse;
public:
    Bst(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            if(reverse){
                node = node->right;
            }
            else{
                node = node->left;
            }
        }
    }
    int next(){
        TreeNode* node = st.top();
        st.pop();
        if(reverse){
            pushAll(node->left);
        }
        else{
            pushAll(node->right);
        }
        return node->val;
    }
};
class Solution{
    public:
    bool findTarget(TreeNode* root, int k) {
       if(root == NULL){
        return false;
       } 
       Bst l(root,false);
       Bst r(root, true);
       int i = l.next();
       int j = r.next();
       while(i < j){
        if(i + j == k){
            return true;
        }
        else if(i + j < k){
            i = l.next();
        }
        else{
            j = r.next();
        }
       }
       return false;
    }
};