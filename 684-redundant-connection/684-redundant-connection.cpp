class Solution {
public:
    int timer=0;
    set<pair<int,int>> bridges;
    void helper(vector<vector<int>>& arr,int n,vector<bool>& vis,vector<int>& tin,vector<int>& low,int node,int par){
        vis[node]=true;
        tin[node]=low[node]=timer;
        ++timer;
        
        for(auto child:arr[node]){
            if(child==par){
                continue;
            }
            if(vis[child]){
                low[node]=min(low[node],tin[child]);
            }
            else{
                helper(arr,n,vis,tin,low,child,node);
                low[node]=min(low[node],low[child]);
                if(low[child]>tin[node]){
                    bridges.insert({node,child});
                }
            }
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> arr(n+1);
        for(auto e:edges){
            arr[e[0]].push_back(e[1]);
            arr[e[1]].push_back(e[0]);
        }
        
        vector<bool> vis(n+1,false);
        vector<int> tin(n+1,-1);
        vector<int> low(n+1,-1);
        
        helper(arr,n,vis,tin,low,1,0);
        
        vector<int> isBridge(n,false);
        for(int i=0;i<n;i++){
            int e1=edges[i][0];
            int e2=edges[i][1];
            
            if(bridges.find({e1,e2})!=bridges.end() || bridges.find({e2,e1})!=bridges.end()){
                isBridge[i]=true;
            }
        }
        vector<int> res;
        for(int i=n-1;i>=0;i--){
            if(!isBridge[i]){
                res.push_back(edges[i][0]);    
                res.push_back(edges[i][1]); 
                break;
            }
        }
        return res;
    }
};