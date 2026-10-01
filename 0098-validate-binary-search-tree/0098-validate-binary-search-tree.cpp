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
#define ll long long 
    bool check(TreeNode* root ,  ll low , ll high ){
        if(!root) return true ;

        if(root->val <= low || root->val >= high) return false;

        return check(root->left , low , root->val) && check(root->right , root->val , high);
    }
    bool isValidBST(TreeNode* root) {
        return check(root , LLONG_MIN , LLONG_MAX);
        
    }
};