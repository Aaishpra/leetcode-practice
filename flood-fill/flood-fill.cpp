class Solution {
    private:
    void dfsfill(vector<vector<int>>& ar, int i, int j, int c0, int c){
        if(i<0 || i>=ar.size()|| j<0 || j>=ar[0].size() || ar[i][j]!=c0) return;
        ar[i][j]=c;
        dfsfill(ar,i+1,j,c0,c);
        dfsfill(ar,i-1,j,c0,c);
        dfsfill(ar,i,j+1,c0,c);
        dfsfill(ar,i,j-1,c0,c);
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         if (image[sr][sc] != newColor){
        dfsfill(image,sr,sc,image[sr][sc],newColor);
             }
        return image;
    }
};