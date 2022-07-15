class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        //LIS solution
        int n=scores.size();
        vector<pair<int,int>> players;
        vector<int> dp(n,0);
        
        for(int i=0;i<n;i++){
            players.push_back({ages[i],scores[i]});
        }
        sort(players.begin(),players.end());
        int mx=0;
        for(int i=0;i<n;i++){
            dp[i]=players[i].second;
            for(int j=0;j<i;j++){
            if(players[i].second>=players[j].second){
                dp[i]=max(dp[i],dp[j]+players[i].second);
            }
        }
        mx=max(mx,dp[i]);
        }
        return mx;
    }
};