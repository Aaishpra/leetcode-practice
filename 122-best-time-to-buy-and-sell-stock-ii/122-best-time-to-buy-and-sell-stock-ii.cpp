class Solution {
public:
    int maxProfit(vector<int>& prices) {
         if(prices.size()<=1) return 0;
	int s1=0,s2=-prices[0];
        
	for(int i=1;i<prices.size();++i) {            
		s1 = max(s1,s2+prices[i]);
		s2 = max(s2, s1-prices[i]);
		
	}
	return max(s1,0);
    }
};