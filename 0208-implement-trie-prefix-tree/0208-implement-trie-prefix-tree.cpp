struct Node{
    vector<Node*>t=vector<Node*>(26,NULL);
    bool isEnd=false;
};

class Trie {
public:
   
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
       
        Node* curr=root;
        
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';   // 0
            if(curr->t[idx]==NULL)
                curr->t[idx]=new Node(); // app
            
            curr=curr->t[idx];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            
            if(curr->t[idx]==NULL)
                return false;
            
            curr=curr->t[idx];
        }
        
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr=root;
        for(int i=0;i<prefix.size();i++){
            int idx=prefix[i]-'a';
            
            if(curr->t[idx]==NULL)
                return false;
            
            curr=curr->t[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */