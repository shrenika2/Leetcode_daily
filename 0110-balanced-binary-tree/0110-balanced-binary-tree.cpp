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

    int help(TreeNode* root){
        if(!root) return 0 ;
        int left = help(root->left);
        int right = help(root->right);
        return 1 + max(left , right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true ;
        
        int a = abs((1+help(root->left)) - (1+help(root->right)));
        return (a==0 || a==-1 || a==1) && isBalanced(root->left) && isBalanced(root->right);
    }
};