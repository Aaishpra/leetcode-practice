class Solution {
public:
     int findCircleNum(vector<vector<int>>& isConnected) {
         int n=isConnected[0].size();
        bool visited[n+1];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        return dfs(isConnected,visited,n);
    }
    void dfsR(int s,vector<vector<int>>& isConnected,bool visited[],int n)
    {
        visited[s]=true;
        for(int it=0;it<n;it++)
        {
            if(isConnected[s][it]==1)
            {
            if(visited[it]==false)
            dfsR(it,isConnected,visited,n);
            }
        }
    }
    int dfs(vector<vector<int>>& isConnected,bool visited[],int n)
    {
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                count++;
                visited[i]=true;
                dfsR(i,isConnected,visited,n);
            }
        }
        return count;
    }
    
};