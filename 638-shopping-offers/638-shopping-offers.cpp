class Solution {
public:
   map<pair<int,vector<int>>,int>mp;               // for memorization of dp states
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price,special,needs,0);
    }
    
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int> needs,int it){
        if(it==special.size()){
            int cost=0;
            for(int i=0;i<needs.size();++i){
                cost+=needs[i]*price[i];
            }
            return cost;
        }
        if(mp.find({it,needs})!=mp.end()) return mp[{it,needs}];
        vector<int>need=needs;
        for(int j=0;j<price.size();++j){
            need[j]=needs[j]-special[it][j];
            if(need[j]<0) return mp[{it,needs}]=solve(price,special,needs,it+1);
        }
        return mp[{it,needs}]=min(solve(price,special,needs,it+1),solve(price,special,need,it)+special[it][price.size()]);          // either choose it or don't choose
    }
};