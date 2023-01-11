class Solution {
public:
    vector<vector<int>> ar;
    vector<int> vis;
    int dfs(int node,vector<bool>& apple){
        int d=0;
        vis[node]=1;
        for(auto child:ar[node]){
            if(vis[child]==0){
                d+=dfs(child,apple);
            }
        }
        return (d || apple[node])?d+1:0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        ar.resize(n);
        vis.resize(n,0);
        
        for(auto e:edges){
            ar[e[0]].push_back(e[1]);
            ar[e[1]].push_back(e[0]);
        }
        int ans=dfs(0,hasApple)-1;
        return max(0,2*ans);
    }
};