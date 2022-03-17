class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
     int n=pairs.size();
        vector<int> dp(n,1);
        if(n==1)return 1;
        sort(pairs.begin(),pairs.end());
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};