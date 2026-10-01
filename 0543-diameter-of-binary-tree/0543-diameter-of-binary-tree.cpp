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
    int ans = 0 ;
    int check(TreeNode* root){
        if (!root) return 0 ;
        int l = check(root->left);
        int r = check(root->right);
        ans = max(ans , l+r);
        return 1 + max(l , r);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        check(root);
        return ans ;
    }
};