class Solution {
public:
    void bfs(vector<vector<int>>& ar,vector<int> &vis,int node){
        vis[node]=1;
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int child:ar[cur]){
                if(vis[child]==0){
                    q.push(child);
                    vis[child]=1;
                }
            }
        }
        
    }
    void dfs(vector<vector<int>>& ar,vector<int> &vis,int node){
        vis[node]=1;
        
        for(auto child:ar[node]){
            if(vis[child]==1)continue;
            else if(vis[child]==0){
                dfs(ar,vis,child);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> ar(n);
        vector<int> vis(n+1,0);
        
        for(auto e:edges){
            ar[e[0]].push_back(e[1]);
            ar[e[1]].push_back(e[0]);
        }
        bfs(ar,vis,source);
        //dfs(ar,vis,source);
        return vis[destination]==1;
    }
};