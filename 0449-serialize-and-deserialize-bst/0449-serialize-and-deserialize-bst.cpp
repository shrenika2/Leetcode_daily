/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void sh(TreeNode* root , string& s){
        if (!root) return ;
        s+=to_string(root->val )+ ',';
        sh(root->left , s);
        sh(root->right , s);
    }
    string serialize(TreeNode* root) {
        string s = "";
        sh(root , s);
        return s ;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* d(vector<int> &pre , int& idx , int low , int high){
        if(idx >= pre.size()){
            return nullptr;
        }
        int val = pre[idx];
        if(val < low || val > high) 
            return nullptr;

        idx++;

        TreeNode* root = new TreeNode(val);
        root->left = d(pre , idx , low , val);
        root->right = d(pre , idx , val , high);
        return root ;
    }
    TreeNode* deserialize(string data) {
        vector<int> pre;

        stringstream ss(data);
        string token ;

        while(getline(ss , token , ',')){
            if(!token.empty()){
                pre.push_back(stoi(token));
            }
        }
        int idx = 0 ;
        return d(pre , idx , INT_MIN , INT_MAX);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;