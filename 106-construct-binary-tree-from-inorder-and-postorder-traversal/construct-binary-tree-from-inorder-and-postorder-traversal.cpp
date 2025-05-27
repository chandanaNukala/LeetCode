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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0) return NULL;
        
        TreeNode* root= new TreeNode(postorder[postorder.size()-1]);
        postorder.pop_back();

        auto it=find(inorder.begin(),inorder.end(),root->val);
        auto root_inorder= it-inorder.begin();

        vector<int> right_inorder(inorder.begin()+root_inorder+1,inorder.end());
        vector<int>left_inorder(inorder.begin(),inorder.begin()+root_inorder);
        root->right=buildTree(right_inorder,postorder);
        root->left=buildTree(left_inorder,postorder);

         return root;

    }
};