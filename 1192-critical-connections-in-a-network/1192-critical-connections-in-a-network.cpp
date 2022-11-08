class Solution {
public:
    vector<vector<int>> bridges;
    int timer;
    void dfs(int node,int p,vector<vector<int>>& ar,vector<int> &vis,vector<int>& low,vector<int> &tin){
        vis[node]=1;
        low[node]=tin[node]=timer++;
        for(int child:ar[node]){
            if(child==p) continue;
            if(vis[child]==1) low[node]=min(low[node],tin[child]);
            else {
                dfs(child,node,ar,vis,low,tin);
                low[node]=min(low[node],low[child]);
                if(low[child]>tin[node])
                    bridges.push_back(vector<int>{node,child});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        timer=0;
        vector<vector<int>> ar(n);
        vector<int> vis(n,0);
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        
        for(auto c:connections){
            ar[c[0]].push_back(c[1]);
            ar[c[1]].push_back(c[0]);
        }
        
        for(int i=0;i<n;i++){
            if(vis[i]==0)
                dfs(i,-1,ar,vis,low,tin);
        }
        return bridges;
    }
};