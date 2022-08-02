class Solution {
public:
    void dfs(unordered_map<string,multiset<string>>& ar,string node,int dep,vector<string>& store,int tot){
        while(ar[node].size()){
            string child=*ar[node].begin();
            ar[node].erase(ar[node].begin());
            dfs(ar,child,dep+1,store,tot);
        }
        store.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n=tickets.size();
        unordered_map<string,multiset<string>> ar;
        vector<string> store;
        for(auto t:tickets){
            ar[t[0]].insert(t[1]);
        }
        
        dfs(ar,"JFK",1,store,n);
        reverse(store.begin(),store.end());
        return store;
    }
};