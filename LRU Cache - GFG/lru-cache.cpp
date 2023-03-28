//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    int size=0;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    list<int>dll;
    LRUCache(int cap)
    {
        // code here
        size=cap;
    }
    void moveTofirst(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
        
    }
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(mp.find(key)==mp.end())return -1;
        
        moveTofirst(key);
        return mp[key].second;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here
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

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends