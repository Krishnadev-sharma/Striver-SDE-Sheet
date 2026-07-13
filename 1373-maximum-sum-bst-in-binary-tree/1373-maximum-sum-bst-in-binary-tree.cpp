/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class NodeValue {
public:
    int minNode, maxNode, maxSum;
    bool isBST;
    NodeValue(int minNode, int maxNode, int maxSum, bool isBST) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
        this->isBST = isBST;
    }
};
class Solution {
public:
    int ans = 0;
    NodeValue solve(TreeNode* root) {
        if (root == NULL) {
            return NodeValue(INT_MAX, INT_MIN, 0, true);
        }
        NodeValue left = solve(root->left);
        NodeValue right = solve(root->right);
        if (left.isBST && right.isBST && root->val > left.maxNode &&
            root->val < right.minNode) {
            int sum = left.maxSum + right.maxSum + root->val;
            ans = max(ans, sum);
            return NodeValue(min(root->val, left.minNode),
                             max(root->val, right.maxNode), sum, true);
        }
        return NodeValue(INT_MIN, INT_MAX, 0, false);
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
    };