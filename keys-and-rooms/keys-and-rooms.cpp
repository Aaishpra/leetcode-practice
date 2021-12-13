class Solution {
public:
    void dfs(vector<vector<int>>& rooms, unordered_set<int>& keys, unordered_set<int>& vis, int node){
        vis.insert(node);
        for(int k:rooms[node]){
            keys.insert(k);
            for(int k:keys){
                if(vis.find(k)==vis.end()){
                    dfs(rooms,keys,vis,k);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        unordered_set<int> vis;
        unordered_set<int> keys;
        dfs(rooms,keys,vis,0);
        return vis.size()==rooms.size();
    }
};