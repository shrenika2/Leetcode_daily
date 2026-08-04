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
    TreeNode* lca(TreeNode* root , int p , int q ){
        if(!root) return nullptr ;
        if(root->val == p || root -> val == q){
            return root ;
        }
        TreeNode* l = lca(root->left , p , q);
        TreeNode* r = lca(root->right , p , q);
        if(l&&r) return root ;
        return l ? l : r;
    }
    bool dfs(TreeNode* root , int x , string &path){
        if(!root) return false ;
        if(root->val == x) return true ;
        path.push_back('L');
        if(dfs(root->left , x , path)){
            return true ;
        }
        path.pop_back();

        path.push_back('R');
        if(dfs(root->right , x , path)){
            return true ;
        }
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int st, int dt) {
        TreeNode* node = lca(root , st , dt);

        string p1 , p2 ;
        dfs(node , st , p1);
        dfs(node , dt , p2);
        string ans(p1.size() , 'U');
        return ans+p2;
    }
};