class Solution {
public:
    vector<int> vis,col;
    bool dfs(vector<vector<int>> &graph,int node,int c){
        vis[node]=1;
        col[node]=c;
        for(int child:graph[node]){
            if(vis[child]==0){
                if(dfs(graph,child,c^1)==false)
                    return false;
            }
            if(col[node]==col[child]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vis.resize(n);
        col.resize(n);
        for(int i=0;i<graph.size();++i){
            if(vis[i]==0){
                bool res=dfs(graph,i,0);
                if(res==false)return false;
            }
        }
        return true;
    }
};