class Solution {
public:
     vector<vector<int>> ar;
    vector<int> vis;
    int cnt=0;
    void dfs(int node){
        vis[node]=1;
        cnt++;
      
        for(auto child:ar[node]){
            if(vis[child]==0){
                dfs(child);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
   ar.resize(n);
        vis.resize(n,0);
    for(auto e:edges){
        ar[e[0]].push_back(e[1]);
        ar[e[1]].push_back(e[0]);
    }
        for(int i:restricted) {
            vis[i]=1;
        }
        
        dfs(0);
        
        return cnt;
        
    }
};