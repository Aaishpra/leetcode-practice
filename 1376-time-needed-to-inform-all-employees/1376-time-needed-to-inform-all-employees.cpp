class Solution {
public:
    int dfs(vector<vector<int>> &graph,vector<int> &informTime,int node){
        int time=0;
        //vis[node]=1;
        for(int child:graph[node]){
          //  if(vis[child]==0){
                time=max(time,dfs(graph,informTime,child));
            //}
        }
        return informTime[node]+time;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
       // vector<int> vis(n,0);
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                graph[manager[i]].push_back(i);
            }
        }
        int time= dfs(graph,informTime,headID);
        return time;
    }
};