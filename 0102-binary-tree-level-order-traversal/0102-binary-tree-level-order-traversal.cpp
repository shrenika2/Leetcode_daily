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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
    return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> le;
            while(sz--){
                TreeNode* el = q.front();
                q.pop();
                le.push_back(el->val);
                if (el->left) q.push(el->left);
                if(el->right) q.push(el->right);
            }
            ans.push_back(le);
            
        }
        return ans;
    }
};