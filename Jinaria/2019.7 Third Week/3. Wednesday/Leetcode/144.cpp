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
    void preorder(TreeNode* node, vector<int> &a) {
        if (node == NULL) return;
        a.push_back(node->val);
        preorder(node->left, a);
        preorder(node->right, a);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> a;
        preorder(root, a);
        return a;
    }
};