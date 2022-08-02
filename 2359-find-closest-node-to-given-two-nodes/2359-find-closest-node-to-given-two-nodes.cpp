class Solution {
public:
    void bfs(vector<vector<int>> &ar,vector<int> &vis,vector<int> &dis,int node){
        vis[node]=1;
        queue<int> q;
        q.push(node);
        dis[node]=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int child:ar[cur]){
                if(vis[child]==0){
                    q.push(child);
                    vis[child]=1;
                    dis[child]=dis[cur]+1;
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>> ar(n);
        vector<int> vis(n,0),vis1(n,0);
        vector<int> dis(n,INT_MAX),dis1(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(edges[i]>-1){
            ar[i].push_back(edges[i]);
            }
        }
        
        bfs(ar,vis,dis,node1);
        bfs(ar,vis1,dis1,node2);
        int mn=INT_MAX;
        int cn=-1;
        for(int i=0;i<n;i++){
        if(mn>max(dis[i],dis1[i])){
            mn=max(dis[i],dis1[i]);
            cn=i;
        }    
        }
        return cn;
    }
};