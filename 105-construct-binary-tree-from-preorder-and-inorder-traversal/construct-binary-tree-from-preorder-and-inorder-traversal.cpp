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
    unordered_map<int,int>in_indices;
    int pre_ptr=0;

    TreeNode* helper(vector<int>preorder, int l,int r){
        if(l>r) return NULL;

        TreeNode* root=new TreeNode(preorder[pre_ptr]);

        int mid_inorder=in_indices[preorder[pre_ptr]];
        pre_ptr++;
        root->left=helper(preorder,l,mid_inorder-1);
        root->right=helper(preorder,mid_inorder+1,r);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // if(preorder.size()==0 || inorder.size()==0){
        //     return NULL;
        // }

        // TreeNode* root=new TreeNode(preorder[0]);

        // //find the root index in inorder
        // auto it=find(inorder.begin(),inorder.end(),preorder[0]);

        // auto root_inorder= it-inorder.begin();

        // //split the inorder
        
        // vector<int> leftIn(inorder.begin(),inorder.begin()+root_inorder);
        // vector<int>rightIn(inorder.begin()+root_inorder+1,inorder.end());

        // //split pre, first root, root_index gives size of the left childs
        // vector<int> leftPre(preorder.begin()+1,preorder.begin()+root_inorder+1);
        // vector<int> rightPre(preorder.begin()+root_inorder+1,preorder.end());


        // root->left=buildTree(leftPre,leftIn);
        // root->right=buildTree(rightPre,rightIn);

        // return root;

        for(int i=0;i<inorder.size();i++){
            in_indices[inorder[i]]=i;
        }
        return helper(preorder,0,inorder.size()-1);

    }
};