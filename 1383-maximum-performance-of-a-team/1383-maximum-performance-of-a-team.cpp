class Solution {
public:
   // static bool comapre(const pair)
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
    
        int mod=1e9+7;
        vector<pair<int,int>> pq;
        for(int i=0;i<speed.size();i++){
            pq.push_back({eff[i],speed[i]});
        }
        sort(pq.rbegin(),pq.rend());
        long long res=0;
        long long sum=0;
        priority_queue<int,vector<int>,greater<int>> minheap;
        
    for(int i=0;i<pq.size();i++){
            sum+=pq[i].second;
            minheap.push(pq[i].second); 
            if(minheap.size()>k){
                sum-=minheap.top();
                minheap.pop();
            }
            
            res=max(res,pq[i].first*sum);
            //pq.pop();
        }
        return res%mod;
    }
};