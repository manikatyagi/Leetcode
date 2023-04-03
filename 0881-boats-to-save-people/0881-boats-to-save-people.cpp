class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int b=0;
        sort(people.begin(),people.end());
        //3,2,2,1   1 2 2 3               1 2 4 5
        //          i   j                 i     j
       
        int i=0;
        int j=people.size()-1;
        
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;
                j--;
            }
            
            else{
                j--;
            
            }
            b++;
        }
        return b;
    }
};