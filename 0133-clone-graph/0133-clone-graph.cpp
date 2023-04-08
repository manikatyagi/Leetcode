/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* curr,  unordered_map<Node*,Node*>&mp){
        vector<Node*>n;
        
        Node* clone=new Node(curr->val);
        
        mp[curr]=clone;
        
        for(auto i: curr->neighbors){
            if(mp.find(i)!=mp.end()){
                n.push_back(mp[i]);
            }
            else{
                n.push_back(dfs(i,mp));
            }
        }
        
        clone->neighbors=n;
        cout<<clone->val<<" ";
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        
        if(node==NULL)return NULL;
        
        if(node->neighbors.size()==0){
            Node* clone=new Node(node->val);
            return clone;
        }
        
        return dfs(node,mp);
    }
};