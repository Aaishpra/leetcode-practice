class Solution {
public:
    int dp[51][51];
    int solve(vector<int>& nums,int i ,int j){
        if(i>=j) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int temp=solve(nums,i,k)+solve(nums,k+1,j)+nums[i-1]*nums[j]*nums[k];
            ans=min(temp,ans);
        }
        return dp[i][j]= ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof dp);
        return solve(values,1,values.size()-1);
    }
};