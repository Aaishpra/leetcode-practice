class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        vector<unordered_map<int,int>> dp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int dif=nums[i]-nums[j];
                if(dp[j].count(dif)>0){
                    dp[i][dif]=dp[j][dif]+1;
                }
                else dp[i][dif]=2;
                result=max(result,dp[i][dif]);
            }
            
        }
        return result;
    }
};