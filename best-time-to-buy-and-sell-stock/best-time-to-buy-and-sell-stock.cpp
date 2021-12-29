class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int ans=0, ans1=0;
        for(int i=1;i<prices.size();i++){
           ans=max(0,ans+=prices[i]-prices[i-1]); 
           
                ans1=max(ans1,ans);
            }
        
        return ans1;
    }
};