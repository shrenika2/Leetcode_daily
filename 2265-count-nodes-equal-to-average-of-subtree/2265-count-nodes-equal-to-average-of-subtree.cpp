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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        tree(root,ans);
        return ans;
    }

    pair<int,int> tree(TreeNode* root, int &ans){
        if(root == nullptr) return {0,0};
        pair<int,int> left = tree(root->left,ans);
        pair<int,int> right = tree(root->right,ans);
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;
        int avg = sum / count;
        if(avg == root->val) ans++;
        return {sum,count};
    }
};

// 0 1 ++
// 1 1 ++
// 9 3 

// 0 0
// 6 1 ++
// 11 2 ++

// 24 6 ++