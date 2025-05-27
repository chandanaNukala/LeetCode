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

        // if(inorder.size()==0) return NULL;
        
        // TreeNode* root= new TreeNode(postorder[postorder.size()-1]);
        // postorder.pop_back();

        // auto it=find(inorder.begin(),inorder.end(),root->val);
        // auto root_inorder= it-inorder.begin();

        // vector<int> right_inorder(inorder.begin()+root_inorder+1,inorder.end());
        // vector<int>left_inorder(inorder.begin(),inorder.begin()+root_inorder);
        // root->right=buildTree(right_inorder,postorder);
        // root->left=buildTree(left_inorder,postorder);

        //  return root;
        for(int i=0;i<inorder.size();i++){
            in_indices[inorder[i]]=i;
        }
        return helper(postorder,0,inorder.size()-1);

    }
};