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
    vector<vector<int>> ans ;
    

   void help(TreeNode* root, int t, vector<int> &path){
        if(!root) return;
        path.push_back(root->val);

        if(!root->left && !root->right){
            if(t==(root->val)){
                ans.push_back(path);
            }
        }
        help(root->left , t - (root->val) , path );
        help(root->right , t - (root->val) , path );
       path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       
        vector<int> path;
       help(root , targetSum , path);
       return ans;
    }
};