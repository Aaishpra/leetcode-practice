class Solution {
public:
    void dfs(int node,vector<vector<int>>& ar,vector<int>& vis){
        vis[node]=1;
        for(int child:ar[node]){
            if(vis[child]==0){
                dfs(child,ar,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& cp) {
        vector<vector<int>> ar(n);
        vector<int> vis(n,0);
        int m=cp.size();
        if(m<n-1)return -1;
        for(auto c:cp){
            ar[c[0]].push_back(c[1]);
            ar[c[1]].push_back(c[0]);
        }
        int cc=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,ar,vis);
                cc++;
            }
        }
        return cc-1;
    }
};