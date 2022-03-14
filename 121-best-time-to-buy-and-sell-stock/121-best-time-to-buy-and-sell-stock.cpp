class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int best=0;
        
        for(int i=1;i<n;i++){
            profit=max(profit+=prices[i]-prices[i-1],0);
            best=max(profit,best);
        }
        return best;
    }
};