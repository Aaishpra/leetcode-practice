class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> ar(n+1);
        for(int i=0;i<times.size();i++){
            ar[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k]=0;
        
        while(!pq.empty()){
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            for(auto& c:ar[node]){
                int child=c.first;
                int wt=c.second;
                if(dist[node]+wt<dist[child]){
                    dist[child]=dist[node]+wt;
                    pq.push({dist[child],child});
                }
            }
        }
        
        int res = 0;
			for (int i = 1; i <= n; i++)
				res = max(res, dist[i]);
				
        return res==INT_MAX?-1:res;
    }
};