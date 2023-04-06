class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         
        unordered_map<int,int>mp;
      
        int j=0;
        int ans=-1;
        
        for(int i=0;i<fruits.size();i++){
            mp[fruits[i]]++;
           
           while(mp.size()>2){
                mp[fruits[j]]--;
                
                if(mp[fruits[j]]==0)mp.erase(fruits[j]);
                
                j++;
            }
            ans=max(i-j+1,ans);
            
        }
        return ans;
    }
};