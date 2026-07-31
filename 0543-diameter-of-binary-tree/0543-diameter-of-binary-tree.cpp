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

        return 1+ max(left , right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0 ;

        return max({help(root->left) + help(root->right) , diameterOfBinaryTree(root->left) , diameterOfBinaryTree(root->right)});
    }
};