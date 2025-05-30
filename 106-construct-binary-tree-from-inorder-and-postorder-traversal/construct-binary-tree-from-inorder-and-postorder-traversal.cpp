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
    unordered_map<int,int>in_indices;
    int pre_ptr=0;

    TreeNode* helper(vector<int>&postorder, int l,int r){
        if(l>r) return NULL;
        TreeNode* root= new TreeNode(postorder[postorder.size()-1]);
        postorder.pop_back();

        int mid_inorder=in_indices[root->val];
       
        root->right=helper(postorder,mid_inorder+1,r);
        root->left=helper(postorder,l,mid_inorder-1);
        

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for(int i=0;i<inorder.size();i++){
            in_indices[inorder[i]]=i;
        }
        return helper(postorder,0,inorder.size()-1);

    }
};