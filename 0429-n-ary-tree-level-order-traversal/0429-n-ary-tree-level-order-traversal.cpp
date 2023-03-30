/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>v;
        if (root==NULL)return v;
        queue<Node*>q;
        
        q.push(root);       //    6 7 8 9 10
        
        while(!q.empty()){
     
            int s=q.size();
            vector<int>r;
            
            while(s-->0){
                Node* f=q.front();
                q.pop();
                r.push_back(f->val);  // 2 3 4 5
                
                for(int i=0;i<f->children.size();i++){
                    
                    q.push(f->children[i]);
                }
                
            }
            
            v.push_back(r); // 1 [2 3 4 5]
            
        }
        return v;
    }
};