class Solution {
public:
    static bool mysort(vector<int>& a,vector<int>& b){
                if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];

    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(),envelopes.end(),mysort);
        vector<int> dp;
        
        for(auto e:envelopes){
           
            
            int it = lower_bound(dp.begin(), dp.end(), e[1]) - dp.begin();
            
            if(it == dp.size()) dp.push_back(e[1]);
            else dp[it] = e[1];
        }
        
        return dp.size();
    }
};