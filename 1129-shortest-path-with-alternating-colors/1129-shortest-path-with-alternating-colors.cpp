class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n,-1);
        vector<vector<pair<int,int>>> ar(n);
        for(auto r:redEdges){
            ar[r[0]].push_back({r[1],0});
        }
        
        for(auto b:blueEdges){
            ar[b[0]].push_back({b[1],1});
        }
        
        vector<vector<bool>> vis(n,vector<bool>(2));
        queue<vector<int>> q;
        q.push({0,0,-1});
        ans[0]=0;
        vis[0][1]=vis[0][0]=true;
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            int node=f[0],steps=f[1],prevcol=f[2];
            for(auto& [child,col]:ar[node]){
                if(!vis[child][col] and col!=prevcol){
                    vis[child][col]=true;
                    q.push({child,steps+1,col});
                    if(ans[child]==-1){
                        ans[child]=steps+1;
                    }
                }
            }
        }
        return ans;
    }
};