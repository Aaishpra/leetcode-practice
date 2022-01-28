class Solution {
    private:
    void dfs(vector<vector<int>>& ar,vector<int>& vis,int node){
        vis[node]=1;
        for(int child:ar[node]){
            if(vis[child]==0){
                dfs(ar,vis,child);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(m<n-1) return -1;
        vector<int> vis(n,0);
        vector<vector<int>> ar(n);
        
        for(auto c:connections){
            ar[c[0]].push_back(c[1]);
            ar[c[1]].push_back(c[0]);
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(ar,vis,i);
                count++;
            }
        }
        return count-1;
    }
};