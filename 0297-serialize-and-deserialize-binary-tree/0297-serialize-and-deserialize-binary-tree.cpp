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
void sh(TreeNode* root , string&s){
    if(!root){
        s+="N,";
        return ;
    }

    s+= to_string(root->val) + ",";
    sh(root->left , s);
    sh(root->right , s);
}

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s ;
        sh(root , s);
        return s ;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* d(vector<string>& nodes, int& idx) {
        if(nodes[idx]=="N"){
            idx++;
            return nullptr ;
        }
        TreeNode* root = new TreeNode(stoi(nodes[idx++]));

        root->left = d(nodes , idx);
        root->right = d(nodes , idx);


        return root ;
    }

    TreeNode* deserialize(string data){
        vector<string> nodes ;
        string cur ;

        for (char c : data){
            if(c==','){
                nodes.push_back(cur);
                cur.clear();
            }else{
                cur+= c;
            }
        }
        int idx = 0 ;
        return d(nodes , idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));