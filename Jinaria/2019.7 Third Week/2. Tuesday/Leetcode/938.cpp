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
    void search(TreeNode* node, vector<int> &arr) {
        if (node == NULL) return;
        search(node->left, arr);
        arr.push_back(node->val);
        search(node->right, arr);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {

        vector<int> arr;

        int ret = 0;
        search(root, arr);
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= L) ret += arr[i];
            if (arr[i] == R) break;
        }
        return ret;
    }
};