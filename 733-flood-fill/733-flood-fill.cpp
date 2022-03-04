class Solution {
public:
    void dfs(vector<vector<int>> &ar,int i,int j, int c0, int c){
        if(i>=0 and i<ar.size() and j>=0 and j<ar[0].size() and ar[i][j]==c0){
            ar[i][j]=c;
            dfs(ar,i+1,j,c0,c);
            dfs(ar,i,j+1,c0,c);
            dfs(ar,i-1,j,c0,c);
            dfs(ar,i,j-1,c0,c);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor){
            dfs(image,sr,sc,image[sr][sc],newColor);
        }
        return image;
    }
};