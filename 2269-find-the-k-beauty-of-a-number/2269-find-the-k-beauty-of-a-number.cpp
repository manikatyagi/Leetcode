class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num); // 240
        
        //30003 3    430043
    //      i
        int c=0;
        
        for(int i=0;i<=s.size()-k;i++){
            string su=s.substr(i,k);
            cout<<su<<" ";
            int n=stoi(su);
            
            if(n!=0 and num%n==0)
                c++;
        }
        
        return c;
    }
};