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
    unordered_map<int , int> pos;
    int idx=0 ;

    TreeNode* built(vector<int> &preorder , int l , int r ){
        if(l>r) return nullptr;
        int root = preorder[idx++];
        TreeNode* node = new TreeNode(root);
        int mid = pos[root];

        node->left = built(preorder , l , mid-1);
        node->right = built(preorder , mid+1 , r);
        return node ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0 ; i < n ; i++){
            pos[inorder[i]]=i;
        }
        return built(preorder , 0 , n-1);
    }
};