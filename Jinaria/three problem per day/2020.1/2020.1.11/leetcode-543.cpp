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
    int maxNum = 0;
    int dfs(TreeNode* node){
        if(node == NULL)
            return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        if(left + right > maxNum)
            maxNum = left + right;
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left + right > maxNum)
            maxNum = left + right;
        return maxNum;
    }
};