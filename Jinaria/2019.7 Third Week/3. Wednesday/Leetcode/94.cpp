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
    void pusharr(TreeNode* node, vector<int> &a) {
        if (node == NULL) return;
        pusharr(node->left, a);
        a.push_back(node->val);
        pusharr(node->right, a);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> a;
        pusharr(root, a);
        return a;
    }
};