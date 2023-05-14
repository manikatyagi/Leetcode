class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        int exor=0;
        
        for(int it:derived){
            exor=exor^it;
        }
       
        return exor==0;
    }
};