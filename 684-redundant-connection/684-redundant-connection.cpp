class UnionFind{
    private:
    vector<int> root;
    vector<int> rank;
    public:
    UnionFind(int sz):root(sz),rank(sz){
        for(int i=0;i<sz;i++){
            root[i]=i;
            rank[i]=1;
        }
    }
    int find(int x){
        if(x==root[x]) return x;
        return root[x]=find(root[x]);
    }
    bool find(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rootx!=rooty){
            if(rank[rootx]>rank[rooty]){
                root[rooty]=rootx;
            }
            else if(rank[rooty]>rank[rootx]){
                root[rootx]=rooty;
            }
            else {
                root[rooty]=rootx;
                rank[rootx]+=1;
            }
            return true;
        }
        return false;
    }
    bool isconnected(int x,int y){
        return find(x)==find(y);
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        UnionFind uf(n+1);
        for(auto e:edges){
            if(uf.find(e[0],e[1])==false) return e;
        }
        return {};
    }
};