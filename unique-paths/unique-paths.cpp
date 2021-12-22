class Solution {
public:
    int uniquePaths(int m, int n) {
        int t[n][m];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( i==0 or j==0) t[i][j]=1;
                else t[i][j]=t[i-1][j]+t[i][j-1];
            }
        }
        return t[n-1][m-1];
    }
};