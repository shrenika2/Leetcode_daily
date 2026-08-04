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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root) return nullptr ;
        if(p->val == root->val) return p ;
        if(q->val == root->val) return q ; 
        TreeNode* l = lowestCommonAncestor(root->left , p , q);
        TreeNode* r =  lowestCommonAncestor(root->right , p , q);

        if(l && r) return root;
        return l ? l:r; 

    }
};