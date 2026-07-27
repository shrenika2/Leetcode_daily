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
    unordered_map<int, int> pos;
    int idx;

    TreeNode* built(vector<int>& postorder, int l, int r) {
        if (l > r) return nullptr;

        int root = postorder[idx--];
        TreeNode* node = new TreeNode(root);
        int mid = pos[root];

        node->right = built(postorder, mid + 1, r);
        node->left = built(postorder, l, mid - 1);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;

        idx = postorder.size() - 1;
        return built(postorder, 0, inorder.size() - 1);
    }
};