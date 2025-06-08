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

private:
   
    TreeNode* tree(istringstream& ss){
        string s;
        ss>>s;
        if(s=="N") return NULL;

        TreeNode* node=new TreeNode(stoi(s));
        node->left=tree(ss);
        node->right=tree(ss);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return " N";
        else{
            return " "+to_string(root->val)+serialize(root->left)+serialize(root->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return tree(ss);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));