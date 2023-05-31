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

    vector<int> postorderTraversal(TreeNode* root) {
        //L R root
         vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>st;
        
        st.push(root);
        
        while(!st.empty()){
            TreeNode* t=st.top();
            
            st.pop();
            ans.push_back(t->val);
            if(t->left)st.push(t->left);
            if(t->right)st.push(t->right);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};