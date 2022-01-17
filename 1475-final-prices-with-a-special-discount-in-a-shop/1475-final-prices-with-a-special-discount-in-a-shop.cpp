class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //Netx Smaller element  to right
        stack<int> s;
        vector<int> res;
        int n=prices.size();
        
        for(int i=n-1;i>=0;i--){
            if(s.size()==0) res.push_back(prices[i]);
            else if(s.size()!=0 and s.top()<=prices[i]) res.push_back(prices[i]-s.top());
            else if(s.size()!=0 and s.top()>=prices[i]){
                while(s.size()>0 and s.top()>prices[i]){
                    s.pop();
                }
                if(s.size()==0) res.push_back(prices[i]);
                else res.push_back(prices[i]-s.top());
            }
            s.push(prices[i]);
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};