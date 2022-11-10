class StockSpanner {
public:
      stack<pair<int,int>> res;
    StockSpanner() {
      
    }
    
    int next(int price) {
        int ans=1;
        while(!res.empty() and price>= res.top().first){
            ans+=res.top().second;
            res.pop();
        }
        res.push({price,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */