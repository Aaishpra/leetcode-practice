class UnionFind{
    public:
    vector<int> root;
    vector<int> rank;
    
    UnionFind(int sz): root(sz),rank(sz) {
        for(int i=0;i<sz;i++){
            root[i]=i;
            rank[i]=1;
        }
    }
    int Find(int x){
        if(x==root[x])
            return x;
        return root[x]=Find(root[x]);
    }
    void unionSet(int x,int y){
        int rx=Find(x);
        int ry=Find(y);
        if(rx!=ry){
            if(rank[rx]>rank[ry])
                root[ry]=rx;
            if(rank[ry]>rank[rx])
                root[rx]=ry;
            else {
                root[ry]=rx;
                rank[rx]+=1;
            }
        }
    }
    bool isconnected(int x,int y){
        return Find(x)==Find(y);
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& grid) {
        int n=grid.size();
        UnionFind uf(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {
                uf.unionSet(i,j);
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
           
                if(uf.root[i]==i)
                    cnt++;
           
        }
        return cnt;
    }
};