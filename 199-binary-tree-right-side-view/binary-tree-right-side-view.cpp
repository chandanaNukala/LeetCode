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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* right=NULL;
            for(int i=q.size();i>0;i--){
                TreeNode* node=q.front();
                q.pop();
                if(node!=NULL){
                    right=node;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(right){
                ans.push_back(right->val);
            }
         
               
                
     
            
        }
        return ans;
    }
};