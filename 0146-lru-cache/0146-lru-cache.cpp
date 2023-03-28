class LRUCache {
public:
    int size=0;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    list<int>dll;
    LRUCache(int capacity) {
        size=capacity;
    }
    
    void moveTofirst(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end()){
            return -1;
        }
        
        moveTofirst(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
       if(mp.find(key)!=mp.end()){
           mp[key].second=value;
           moveTofirst(key);
       }
       else{
           dll.push_front(key);
           mp[key]={dll.begin(),value};
           size--;
       }
        if(size<0){
            mp.erase(dll.back());
            dll.pop_back();
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */