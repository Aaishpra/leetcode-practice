class Solution {
public:
    //Euclerian path
    void dfs(unordered_map<string,multiset<string>>& graph,vector<string>& store,string start){
        while(graph[start].size()>0){
            auto next=*graph[start].begin();
            graph[start].erase(graph[start].begin());
            dfs(graph,store,next);
        }
        store.push_back(start);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> graph;
        for(auto t:tickets){
            graph[t[0]].insert(t[1]);
        }
        vector<string> store;
        dfs(graph,store,"JFK");
        reverse(store.begin(),store.end());
        return store;
        
    }
};