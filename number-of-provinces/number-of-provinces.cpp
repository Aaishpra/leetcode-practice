class Unionfind{
    public:
 Unionfind(int n): par(n),rank(n),count(n){
     for(int i=0;i<n;i++){
         par[i]=i;
         rank[i]=1;
     }
 }
    int find(int x){
        if(x==par[x])return x;
        return par[x]=find(par[x]);
    }
    void uni(int x,int y){
        auto xp=find(x);
        auto yp=find(y);
        if(xp!=yp){
        if(xp<yp){
            par[xp]=yp;
        }
        else if(xp>yp){
            par[yp]=xp;
        }
        else{
            par[yp]=xp;
            rank[xp]++;
        }
            count--;
        }
        //count--;
    }
    bool connected(int x,int y){
        return find(x)==find(y);
    }
    int getCount(){
        return count;
    }
    private:
    vector<int> par,rank;
    int count;
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
    Unionfind uf(n);
        if(n==0)return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    uf.uni(i,j);
                }
            }
        }
        return uf.getCount();
    }
};