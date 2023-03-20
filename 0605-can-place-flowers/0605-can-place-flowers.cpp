class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      // 01010100        10100100
        
        
        for(int i=0;i<flowerbed.size();i++){
          if(n==0)break;
            
            if(flowerbed[i]==0 and (i==0 or flowerbed[i-1]==0)){
                if(i==flowerbed.size()-1 or flowerbed[i+1]==0){
                    n--;
                    
                    flowerbed[i]=1;
                }
            }
        }
        if(n==0)return true;
        else
            return false;
      
    }
};