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
    int maxLevelSum(TreeNode* root) {
        int max_sum=INT_MIN;
        if(root==NULL) return max_sum;
    int ans=0;
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        while(!q.empty()){
              int sum=0;
              int N=q.size();
            while(N--){
                TreeNode* node=q.front();
                q.pop();
              
               
                    sum+=node->val;
                    if(node->left)q.push(node->left);
                    if(node->right)q.push(node->right);

               
              
            }
            if(sum>max_sum){
                max_sum=sum;
                ans=level;
            }
              level++;
        }
        return ans;
    }
};