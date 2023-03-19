class Solution {
public:
    int distMoney(int money, int children) {
        
        if(money<children)return -1;
        
        money=money-children; // give 1 dollar to every child so now total money is money-child ie 17
        
        int ans=0;
        for(int i=1;i<children;i++){   // not take last children
            
            if(money>=7){
                money=money-7;  // 10 3
                ans++; // 1 2
            }
            else{
                return ans;
            }
        }
        
        if(money==3){
            ans--;
        }
        if(money==7)ans++;
        return ans;
       
    }
};