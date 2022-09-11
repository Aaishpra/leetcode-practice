class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
    
        int mod=1e9+7;
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<speed.size();i++){
            pq.push({eff[i],speed[i]});
        }
        long long res=0;
        long long sum=0;
        priority_queue<int,vector<int>,greater<int>> minheap;
        
    while(!pq.empty()){
            sum+=pq.top().second;
            minheap.push(pq.top().second); 
            if(minheap.size()>k){
                sum-=minheap.top();
                minheap.pop();
            }
            
            res=max(res,pq.top().first*sum);
            pq.pop();
        }
        return res%mod;
    }
};