class Solution {
public:
    vector<vector<pair<int,int>>> ar;
    int dijksatra(int node,int n,int dt){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[node]=0;
        pq.push({0,node});
        
        while(!pq.empty()){
            int cur=pq.top().second;
            int cur_dist=pq.top().first;
            pq.pop();
            for(auto child:ar[cur]){
                if(dist[child.first]>child.second+cur_dist){
                    dist[child.first]=child.second+cur_dist;
                    pq.push({dist[child.first],child.first});
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(dist[i]<=dt){
                cnt++;
            }
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
      
        ar.resize(n);
        for(auto e:edges){
            ar[e[0]].push_back({e[1],e[2]});
            ar[e[1]].push_back({e[0],e[2]});
        }
        
        int ans=-1,mn=INT_MAX;
        
        for(int i=0;i<n;i++){
            int res=dijksatra(i,n,dt);
            if(res<=mn){
                mn=res;
                ans=i;
            }
        }
        return ans;
    }
};