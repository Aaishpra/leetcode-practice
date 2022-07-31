class Solution {
public:
   void dfs(vector<vector<int>> &ar, int node, vector<int> &dist,vector<int>& vis,int d)
    {vis[node]=1;
     dist[node]=d;
       for(auto child:ar[node]){
           if(vis[child]==0){
               dfs(ar,child,dist,vis,dist[node]+1);
           }
       }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
     int n=edges.size();
        vector<vector<int>> ar(n);
        vector<int> vis1(n,0),vis2(n,0);
          vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
        for(int i=0;i<n;i++){
            if(edges[i]>-1){
                ar[i].push_back(edges[i]);
            }
        }
        dfs(ar,node1,dist1,vis1,0);
        dfs(ar,node2,dist2,vis2,0);
        int mx = INT_MAX, ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (mx > max(dist1[i], dist2[i]))
            {
                mx = max(dist1[i], dist2[i]);
                ans = i;
            }
        }
        return ans;
        
        
    }
};