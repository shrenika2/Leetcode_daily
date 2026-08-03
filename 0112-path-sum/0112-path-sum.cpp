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
    bool help(TreeNode* root , int t ){
        if(!root) return false;
        if(!root && t==0) return true ;
       
        if (!root->left && !root->right){
            return t == root->val;
        }
       return  help(root->left , t-(root->val)) ||
        help(root->right , t-(root->val));
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
       
        return help(root , targetSum);
    }
};