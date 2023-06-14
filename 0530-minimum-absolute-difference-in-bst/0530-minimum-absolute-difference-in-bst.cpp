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
    TreeNode* prev=NULL;
    void func(TreeNode* root,int& ans){
        
        if(root==NULL)return ;
        
        func(root->left,ans);
        
        if(prev!=NULL){
            ans=min(ans,abs(root->val-prev->val));
            cout<<ans<<" ";
        }
        
        prev=root; //1
        
        func(root->right,ans);
        
        
    }
    int getMinimumDifference(TreeNode* root) {
        
        int ans=INT_MAX;
        func(root,ans);
        return ans;
    }
};