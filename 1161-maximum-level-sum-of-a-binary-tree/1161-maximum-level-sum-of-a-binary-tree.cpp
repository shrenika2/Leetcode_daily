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

    int maxLevelSum(TreeNode* root) {
        vector<pair<int , int>> anss;
        queue<TreeNode*> q ;
        q.push(root);
        int cnt = 1;
        while(!q.empty()){
            int sz = q.size();
            int sm = 0 ;
            while(sz--){
                auto node = q.front();
                q.pop();
                sm+=node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
              anss.push_back({sm , cnt});
              cnt++;
        }
        sort(anss.begin() , anss.end());
        int mx = INT_MIN;
        int ans = 1;

        for (auto &it : anss) {
            if (it.first > mx) {
                mx = it.first;
                ans = it.second;
            }
        }

        return ans;
        
    }
};