class Solution {
public:
  bool dfs(int node,int c,vector<vector<int>>& ar,vector<int>& vis,vector<int>& col){
        vis[node]=1;
        col[node]=c;
        for(int child:ar[node]){
        if(vis[child]==0) {
            if(dfs(child,c^1,ar,vis,col)==false) return false;
        }
            else if(col[node]==col[child]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n,vector<vector<int>> dislikes){
        //  int n=dislikes.size();
        vector<vector<int>> graph(n+1);
        for(auto d:dislikes){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
         bool flag=true;
      
        vector<int> vis(n+1,0);
        vector<int> col(n+1);
        
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
               bool res=dfs(i,0,graph,vis,col);
                if(res==false) return false;
            }
        }
        return flag;
    }
};