class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end());
        if(n==0)return 0;
        vector<int> dp(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
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