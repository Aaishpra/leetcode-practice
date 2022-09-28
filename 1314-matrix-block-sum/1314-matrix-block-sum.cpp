class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {  
        vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size()));
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
               int temp=0;
                for(int r=i-k;r<=i+k;r++){
                    for(int c=j-k;c<=j+k;c++){
                       if(r<0 or c<0 or r>=mat.size() or c>=mat[0].size()) continue;
                        temp+=mat[r][c];
                       
                    }
                }
                dp[i][j]=temp;
                }
            }
        
        return dp;
    }
};