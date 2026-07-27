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
        int idx = 0 ;

        TreeNode* build(vector<int>& preorder , int inL , int inR) {
            if(inL > inR) return nullptr;

            int r = preorder[idx++];
            TreeNode* root = new TreeNode(r);
            int mid = pos[r];

            root->left = build(preorder , inL , mid-1);
            root->right = build(preorder , mid+1 , inR);

            return root;
        }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0 ; i < n ; i++){
            pos[inorder[i]]=i;
        }
        return build(preorder , 0 , n-1);
    }
};