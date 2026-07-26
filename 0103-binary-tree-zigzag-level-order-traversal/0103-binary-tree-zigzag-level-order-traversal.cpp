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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>anss ;
        
        queue<TreeNode*> q ;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> path ;
            while(sz--){
                auto node = q.front();
                q.pop();

                path.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            anss.push_back(path);
        }
        for (int i = 1 ; i < anss.size() ; i+=2){
            reverse(anss[i].begin() , anss[i].end());
        }
        return anss;
    }
};