class Solution {
public:
    int timer;
    vector<vector<int>> bridges;
    void dfs(int node,int p,vector<vector<int>>& ar,vector<int>& vis,vector<int>& tin,vector<int>& low){
        vis[node]=1;
        tin[node]=low[node]=timer++;
        
        for(auto child: ar[node]){
        if(child==p) continue;
            if(vis[child]==1){
                low[node]=min(low[node],tin[child]);
            }
            else{
                dfs(child,node,ar,vis,tin,low);
                low[node]=min(low[node],low[child]);
                if(low[child]>tin[node])
                    bridges.push_back(vector<int>{node,child});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> vis(n,0);
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        vector<vector<int>> ar(n);
        timer=0;
        for(auto& c:connections){
            ar[c[0]].push_back(c[1]);
            ar[c[1]].push_back(c[0]);
        }
        
        for(int i=0;i<n;i++){
            if(vis[i]==0)
                dfs(i,-1,ar,vis,tin,low);
        }
        return bridges;
    }
};