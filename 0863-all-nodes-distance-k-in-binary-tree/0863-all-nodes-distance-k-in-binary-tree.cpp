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
    unordered_map<TreeNode* , TreeNode*> parent;
    void bp(TreeNode* root){
        if(!root) return ;
        if(root->left){
            parent[root->left]=root;
            bp(root->left);
        }
        if(root->right){
            parent[root->right]=root;
            bp(root->right);
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        bp(root);
        queue<TreeNode*>q;
        unordered_set<TreeNode*>vis;

        q.push(target);
        vis.insert(target);
    int dist = 0 ;
        while(!q.empty()){
            int sz = q.size();
            if(dist==k) break;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis.count(node->left)){
                    vis.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !vis.count(node->right)){
                    vis.insert(node->right);
                    q.push(node->right);
                }
                if(parent[node] && !vis.count(parent[node])){
                    vis.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            dist++;
        }
        vector<int> ans ;

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans ;
    }
};