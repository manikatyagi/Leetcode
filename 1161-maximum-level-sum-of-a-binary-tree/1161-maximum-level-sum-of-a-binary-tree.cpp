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
       
        queue<TreeNode*>q;
        q.push(root);
        int s=INT_MIN;
        int l=0;
        int ans=1;
        while(!q.empty()){
            int n=q.size();
             int sum=0;
            l++;
            while(n-->0){
                
                TreeNode* t=q.front();
                
                q.pop();
                
                sum+=t->val;
                
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                
            }
            
           
            if(s<sum){
               ans=l; 
                s=sum;
            }
            
            
        }
        return ans;
    }
};