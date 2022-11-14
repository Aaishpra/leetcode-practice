class UnionFind{
    private:
    vector<int> root;
    vector<int> rank;
    public:
    UnionFind(int sz): rank(sz) ,root(sz){
        for(int i=0;i<sz;i++){
            root[i]=i;
            rank[i]=1;
        }
    }
    int find(int x){
        if(x==root[x])
            return x;
        return root[x]=find(root[x]);
    }
    
    bool unionSet(int x,int y){
        int root_x=find(x);
        int root_y=find(y);
        if(root_x !=root_y){
            if(rank[root_x]>rank[root_y]){
                root[root_y]=root_x;
            }
            else if(rank[root_x]<rank[root_y]){
                root[root_x]=root_y;
            }
            else{
                root[root_y]=root_x;
                rank[root_x]+=1;
            }
            return true;
        }
        return false;
    }
    bool isConnected(int x,int y){
        return find(x)==find(y);
    }
    
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        UnionFind uf(n+1);
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if( stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]){
                    if(uf.unionSet(i,j)) 
                        cnt++;
                }
            }
        }
    return cnt;
    }
    
};