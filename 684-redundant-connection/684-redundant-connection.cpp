class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int> &vis,int node,int par=-1){
        vis[node]=1;
        for(int child: graph[node]){
            if(vis[child]==0){
                if(dfs(graph,vis,child,node)==true)
                    return true;
            }
            else if(child!=par)
                return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> graph(n+1);
        vector<int> vis(n+1,0);
        
        for(auto& e:edges){
            fill(vis.begin(),vis.end(),0);
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            if(dfs(graph,vis,e[0])) return e;
        }
        return {};
    }
};