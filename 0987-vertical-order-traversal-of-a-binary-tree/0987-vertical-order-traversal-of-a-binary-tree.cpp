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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,vector<int>>>mp;
        
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        int level=0;
        while(!q.empty()){
            auto t=q.front();
            TreeNode* n=t.first;
            int h=t.second.first;
            int l=t.second.second;
            q.pop();
              
            mp[h][l].push_back(n->val);
            
            if(n->left)q.push({n->left,{h-1,l+1}});
            if(n->right)q.push({n->right,{h+1,l+1}});
        }
        
        for(auto it:mp){
            vector<int>curr;
            for(auto& i:it.second){
                
                sort(i.second.begin(),i.second.end());
                
                
                for(int j=0;j<i.second.size();j++){
                    curr.push_back(i.second[j]);
                }
            }
            ans.push_back(curr);
        }
        
      
       return ans; 
    }
};