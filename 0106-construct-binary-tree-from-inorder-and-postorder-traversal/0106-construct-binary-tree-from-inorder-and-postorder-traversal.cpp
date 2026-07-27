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
    int idx = 0 ;
    unordered_map<int , int> pos;

    TreeNode* built(vector<int> &postorder , int l , int r){
        if(l>r) return nullptr;

        int root = postorder[idx++];
        TreeNode* node = new TreeNode(root);
        int mid = pos[root];

        
        node->right = built(postorder , mid+1 , r);
        node->left = built(postorder , l , mid-1);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        reverse(postorder.begin() , postorder.end());
        for (int i = 0 ; i < n ; i++){
            pos[inorder[i]]=i;
        }
        return built(postorder , 0 , n-1);
        
    }
};