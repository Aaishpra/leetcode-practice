class Solution {
public:
    long long dp[21][21][2];
    long long solve(vector<int>& nums,int i,int j,int c){
        if(i>j)return 0;
        if(dp[i][j][c]!=-1)return dp[i][j][c];
        if(c==0) return dp[i][j][c]=max(nums[i]+solve(nums,i+1,j,1),nums[j]+solve(nums,i,j-1,1));
        else return dp[i][j][c]=min(solve(nums,i+1,j,0),solve(nums,i,j-1,0));
      
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        long long sum=accumulate(nums.begin(),nums.end(),0);
        long long one=solve(nums,0,nums.size()-1,0);
        long long two=sum-one;
        return one>=two;
    }
};