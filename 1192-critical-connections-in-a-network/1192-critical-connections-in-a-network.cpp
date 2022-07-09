class Solution {
public:

vector<bool> visited;
vector<int> tin, low;
int timer;
vector<vector<int>> res;
void dfs(int v, int p, vector<vector<int>>& adj) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v, adj);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                res.push_back({to,v});
        }
    }
}


vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    timer = 0;   
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
         vector<vector<int>> adj(n);
        for(auto c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i,-1,adj);
    }
        return res;
    }
};