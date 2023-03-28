class Solution {
public:
    vector<int> nextsmaller(vector<int>& heights,int n){
        stack<int>st;
    
        vector<int>v(n);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i])
                st.pop();
                
            if(st.empty())
                v[i]=-1;
            else
                v[i]=st.top();
            
            st.push(i);
        }
        return v;
    }
    
    vector<int> prevsmaller(vector<int>& heights,int n){
        stack<int>st;
    
        vector<int>v(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>=heights[i])
                st.pop();
                
            if(st.empty())
                v[i]=-1;
            else
                v[i]=st.top();
            
            st.push(i);
        }
        return v;
    }
    int largestRectangleArea(vector<int>& heights) {
        
      int n = heights.size();
        int area=-999;
      vector<int>next(n);
      next=nextsmaller(heights,n);
     
      vector<int>prev(n);
      prev=prevsmaller(heights,n);
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            
            if(next[i]==-1)next[i]=n;
            
            
            int l=heights[i];
            int b=next[i]-prev[i]-1;
            
            ans=max(ans,l*b);
            
        }
       
       return ans;
    }
    
};