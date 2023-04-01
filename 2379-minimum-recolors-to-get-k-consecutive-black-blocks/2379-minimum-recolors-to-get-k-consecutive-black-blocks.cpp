class Solution {
public:
    int minimumRecolors(string b, int k) {
        // 01234567
        // WBBWWBBWBW
        //"WBWBBBW"   2
     //    
        int c=0;
        int ans=INT_MAX;
        int l=0;
        for(int i=0;i<b.size();i++){
            
            if(b[i]=='W')c++;
            if(i>=k-1){
                ans=min(ans,c);
                
                if(b[l]=='W')
                    c--;
        
               l++; 
                
            }
        }
        return ans;
    }
};