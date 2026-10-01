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
class Solution {
public:
    int mx(TreeNode* root){
        if(!root) return 0 ;
        int left = mx(root->left);
        int right = mx(root->right);
        return 1 + max(left , right);
    }
    int maxDepth(TreeNode* root) {
        if (!root) return 0 ;

        return mx(root) ;
    }
};