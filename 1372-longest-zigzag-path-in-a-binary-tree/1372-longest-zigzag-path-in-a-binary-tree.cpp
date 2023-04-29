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
   
    void solve(bool dirc , TreeNode* root, int& max_len , int len){
        
        if(root==NULL)return ;
        
        max_len=max(max_len,len);
        
        solve(0,root->left,max_len,dirc?len+1:1);
        solve(1,root->right,max_len,dirc?1:len+1);
    }
    int longestZigZag(TreeNode* root) {
       int max_len=0;
        
        solve(0,root,max_len,0);
        solve(1,root,max_len,0);
        
        return max_len;
    }
};