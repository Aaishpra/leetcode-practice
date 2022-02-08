class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int n=prices.size();
        int curr=0;
        int best=0;
        for(int i=1;i<n;i++){
            curr=max(curr+=prices[i]-prices[i-1],0);
            best=max(curr,best);
        }
        return best;
    }
};