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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL){
            if(t2 == NULL){
                return NULL;
            }
            else{
                return t2;
            }
        }
        else{
            if(t2 == NULL){
                return t1;
            }
        }
        
        t1->val += t2->val;
        if(t1->left == NULL)
            t1->left = mergeTrees(t1->left, t2->left);
        else
            mergeTrees(t1->left, t2->left);
        if(t1->right == NULL)
            t1->right = mergeTrees(t1->right, t2->right);
        else
            mergeTrees(t1->right, t2->right);
        return t1;
    }
};