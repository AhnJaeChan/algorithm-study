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
    int numOfSum = 0;
    void makeSubSum(TreeNode* node, int num){
        node->val += num;
        if(node->left)
            makeSubSum(node->left, node->val);
        if(node->right)
            makeSubSum(node->right, node->val);
    }
    void findSumPath(TreeNode* node, int sum, int curVal, int flag){
        if(node == NULL)
            return;
        if(flag && node->val - curVal == sum)
            numOfSum++;
        findSumPath(node->left, sum, curVal, true);
        findSumPath(node->right, sum, curVal, true);
    }
    void inorder(TreeNode* node, int sum){
        if(node){
            findSumPath(node, sum, node->val, false);
            inorder(node->left, sum);
            inorder(node->right, sum);    
        }
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(root){
            makeSubSum(root, 0);
            findSumPath(root, sum, 0, true);
            inorder(root, sum);    
        }
        
        return numOfSum;
    }
};