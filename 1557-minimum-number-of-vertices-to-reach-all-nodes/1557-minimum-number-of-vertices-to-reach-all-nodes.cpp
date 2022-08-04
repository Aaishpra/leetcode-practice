class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ar(n);
        vector<int> in(n,0);
        for(auto e:edges){
            ar[e[0]].push_back(e[1]);
            in[e[1]]++;
        }
        vector<int> store;
        for(int i=0;i<n;i++){
            if(in[i]==0) store.push_back(i);
        }
        return store;
    }
};