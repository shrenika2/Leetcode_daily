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
    bool check(TreeNode* root , int t ){
        if(!root) return false;
        t -= root->val;
        if(!root->left && !root->right && t==0){
            return true ;
        } 
        return check(root->left , t )||
        check(root->right , t);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root ,targetSum );
    }
};