class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int c){
        if(sr<0 or sc<0 or sr>=image.size() or sc>=image[0].size())return;
        
        
        if(image[sr][sc]==color or image[sr][sc]!=c)return;
        
        image[sr][sc]=color;
        
        
        dfs(image,sr+1,sc,color,c);
        dfs(image,sr-1,sc,color,c);
        dfs(image,sr,sc+1,color,c);
        dfs(image,sr,sc-1,color,c);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc]==color)return image;
        int c=image[sr][sc];
        
        dfs(image,sr,sc,color,c);
        
        return image;
    }
};