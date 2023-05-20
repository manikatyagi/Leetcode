class Solution {
public:
    long long mod=1000000007;
    
    long long power(long long x,long long y){
        if(y==0)return 1;
        
        long long ans=power(x,y/2);
        ans=ans*ans;
        ans%=mod;
        
        if(y%2!=0)ans=ans*x;
        ans%=mod;
        
        return ans;
        
    }
    int countGoodNumbers(long long n) {
        
        // 5^e * 4^o e=even number of places o=odd number of places
        // 5^(n/2+n%2) * 4^(n/2)
        long long odd=n/2;// 2
        long long even=n/2+(n%2); //3
        
        return (power(5,even)*power(4,odd))%mod;
    }
};