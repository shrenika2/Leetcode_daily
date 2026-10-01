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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q ;
        vector<int> ans ;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int sm = 0;
            while(sz--){
                TreeNode* el = q.front();
                q.pop();
                if(el->left) q.push(el->left);
                if(el->right) q.push(el->right);
                sm = el->val;
            }
            ans.push_back(sm);
        }
        return ans ;
    }
};